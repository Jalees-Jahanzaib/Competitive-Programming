#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 20005;
const int MAXLOG = 20;

vector<vector<ii>> G;

bool seen[MAX];
int depth[MAX];
int dp[MAX][MAXLOG], mn[MAX][MAXLOG];
int f[MAX];

int find(int x) {
    return f[x] = (f[x] == x ? x : find(f[x]));
}

void merge(int a, int b) {
    f[find(a)] = find(b);
}

void init(int n) {
    for(int i = 0; i <= n; i++) {
        f[i] = i;
    }
}

void dfs(int u, int d) {
    seen[u] = true;
    depth[u] = d;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first;
        int w = G[u][i].second;
        if(!seen[v]) {
            dfs(v, d + 1);
            dp[v][0] = u;
            mn[v][0] = w;
        }
    }
}



int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    //int ans = INT_MAX;
    for(int i = MAXLOG-1; i >= 0; i--)
        if(depth[ dp[a][i] ] >= depth[b]) {
            //ans = min(ans, mn[a][i]);
            a = dp[a][i];
        }
    //if(a == b) return ans;
    if(a == b) return a;
    for(int i = MAXLOG-1; i >= 0; i--)
        if(dp[a][i] != dp[b][i]) {
            //ans = min(ans, mn[a][i]);
            //ans = min(ans, mn[b][i]);
            a = dp[a][i],
            b = dp[b][i];
        }
    //ans = min(ans, mn[a][0]);
    //ans = min(ans, mn[b][0]);
    //return ans;
    return dp[a][0];
}

void make_tree(int m, vector<vector<ii>> &G) {
    vector<iii> e;
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        e.push_back(iii(w, ii(a, b)));
    }

    sort(e.rbegin(), e.rend());

    for(int i = 0; i < m; i++) {
        int u = e[i].second.first;
        int v = e[i].second.second;
        int w = e[i].first;
        if( find(u) != find(v)) {
//            cout << " u = " << u << " v = " << v << endl;
            merge(u, v);
            G[u].push_back(ii(v, w));
            G[v].push_back(ii(u, w));
        }
    }
}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif

    int n, m, s;
    while(cin >> n >> m >> s) {
        memset(seen, false, sizeof seen);
        init(n);

        G = vector<vector<ii>> (n+1);
        make_tree(m, G);

        dfs(1, 1);

        dp[1][0] = 1;
        mn[1][0] = INT_MAX;
        for(int j = 0; j < MAXLOG - 1; j++)
            for(int i = 1; i <= n; i++) {
                dp[i][j + 1] = dp[ dp[i][j] ][j];
                mn[i][j + 1] = min(mn[ dp[i][j] ][j], mn[i][j]);
            }

        while(s--) {
            int a, b; cin >> a >> b;
            int x = lca(a, b);
            assert(x != INT_MAX);
            if(x == INT_MAX) x = 0;
            cout << x << "\n";
        }
    }

}
