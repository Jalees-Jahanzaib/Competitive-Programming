#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll INF = LLONG_MAX/3;
const int MAX = 2e4+10;
const int LOG2 = 18;

vector<vector<ii>> g;
map<int, int> id;
vector<ll> value;

int t[MAX], curt, depth[MAX], dp[MAX][LOG2], component[MAX], curcomponent;
ll acc[MAX][LOG2], sum[MAX];
bool seen[MAX], positive[MAX];

void go(int u, int p, int d) {
    t[u] = d;
    component[u] = curcomponent;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if(v == p) continue;
        int positive = d%2 == 0;
        if(t[v] == -1) {
            sum[v] = sum[u] + (positive ? w : -w);
            go(v, u, d+1);
        } else {
            if((t[u] - t[v])%2 == 0 && t[v] < t[u]) {
                value[v] = (sum[u] - sum[v] + (positive ? w : -w)) / 2;
                if(!positive)
                    value[v] *= -1;
            }
        }
    }
}

void expand(int u) {
    seen[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        ll w = g[u][i].second;
        if(!seen[v] && value[v] == -INF) {
            value[v] = w - value[u];
            expand(v);
        }
    }
}

int add(int x) {
    if(id.count(x)) return id[x];
    int t = id.size();
    return id[x] = t;
}

void dfs(int u, int d) {
    depth[u] = d;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if(!depth[v]) {
            dfs(v, d+1);
            dp[v][0] = u;
            acc[v][0] = d&1 ? -w : w;
            if (d&1)
                positive[v] = false;
        }
    }
}

void build(int n) {
    memset(depth, 0, sizeof depth);
    memset(positive, 1, sizeof positive);
    for(int i = 0; i < n; i++) {
        if(!depth[i] && value[i] == -INF) {
            dp[i][0] = i;
            acc[i][0] = 0;
            dfs(i, 1);
        }
    }

    for(int j = 0; j < LOG2-1; j++) {
        for(int i = 0; i < n; i++) {
            dp[i][j+1] = dp[ dp[i][j] ][j];
            acc[i][j+1] = acc[i][j] + acc[dp[i][j]][j];
        }
    }
}

int get_ancestor(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = LOG2-1; i >= 0; i--) {
        if(depth[ dp[a][i] ] >= depth[b]) {
            a = dp[a][i];
        }
    }
    if(a == b) return a;
    for(int i = LOG2-1; i >= 0; i--) {
        if(dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

ll query(int a, int anc) {
    ll s = 0;
    for(int i = LOG2-1; i >= 0; i--) {
        if(depth[ dp[a][i] ] >= depth[anc]) {
            s += acc[a][i];
            a = dp[a][i];
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif // LOCAL

    int m, q;
    while(cin >> m >> q && (m+q) != 0)  {
        id.clear();
        g.assign(m*2, vector<ii>());
        value.assign(m*2, -INF);
        for(int i = 0; i < m; i++) {
            int x, y, v; cin >> x >> y >> v;
            x = add(x);
            y = add(y);
            if(x == y) value[x] = v;
            else {
                g[x].push_back(ii(y, v));
                g[y].push_back(ii(x, v));
            }

        }

        int n = id.size();
        memset(t, -1, sizeof t);
        memset(sum, 0, sizeof sum);

        curcomponent = 0;
        for(int i = 0; i < n; i++) {
            if(t[i] == -1) {
                ++curcomponent;
                go(i, -1, 0);
            }
        }

        memset(seen, false, sizeof seen);

        for(int i = 0; i < n; i++)
            if(!seen[i] && value[i] != -INF)
                expand(i);

        build(n);
        while(q--) {
            int x, y; cin >> x >> y;
            if(!id.count(x) || !id.count(y)) {
                cout << "*" << endl;
            } else {
                x = add(x);
                y = add(y);
                if (value[x] != -INF && value[y] != -INF) {
                    x == y ? cout << value[x] << endl : cout << value[x] + value[y] << endl;
                    continue;
                }
                if(component[x] != component[y]) {
                    cout << "*" << endl;
                    continue;
                }
                int anc = get_ancestor(x, y);
                int d = depth[x] + depth[y] - 2 * depth[anc];
                if(d % 2 == 0) {
                    cout << "*" << endl;
                } else {
                    ll sumx = query(x, anc);
                    ll sumy = query(y, anc);

                    if(!positive[x]) sumx *= -1;
                    if(!positive[y]) sumy *= -1;

                    cout << sumx + sumy << endl;
                }
            }
        }
        cout << "-" << endl;
    }
}