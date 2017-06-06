#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 100010;
const int INF = INT_MAX/3;
const int MAXLOG = 20;

int len[MAX], f[MAX], depth[MAX], dp[MAX][MAXLOG];
multiset<int> ans[MAX];
bool state[MAX];
bool done[MAX];

vector<vector<int>> G;

int dfs(int u, int p) {
    len[u] = 1;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v != p && !done[v])
            len[u] += dfs(v, u);
    }
    return len[u];
}

int decompose(int cen) {
    int target = dfs(cen, -1)/2, p = -1;
    bool ok = false;
    while(!ok) {
        ok = true;
        for(int i = 0; i < G[cen].size(); i++) {
            int v = G[cen][i];
            if(p != v && !done[v] && len[v] > target) {
                ok = false;
                p = cen;
                cen = v;
            }
        }
    }

    done[cen] = true;
    for(int i = 0; i < G[cen].size(); i++) {
        int v = G[cen][i];
        if(!done[v]) {
            f[ decompose(v) ] = cen;
        }
    }

    return cen;
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = MAXLOG-1; i >= 0; i--)
        if(depth[ dp[a][i] ] >= depth[b]) {
            a = dp[a][i];
        }
    if(a == b) return a;
    for(int i = MAXLOG-1; i >= 0; i--)
        if(dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    return dp[a][0];
}

void go(int u, int p, int d) {
    depth[u] = d;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v != p) {
            go(v, u, d + 1);
            dp[v][0] = u;
        }
    }
}

void pre(int r, int n) {
    for(int i = 1; i <= n; i++) ans[i].insert(INF);

    dp[r][0] = 0;
    go(r, -1, 1);
    for(int j = 0; j < MAXLOG-1; j++)
        for(int i = 0; i <= n; i++)
            dp[i][j + 1] = dp[ dp[i][j] ][j];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2*depth[lca(u, v)];
}

void update(int x) {
    int u = x;
    for(int u = x; u != -1; u = f[u]) {
        if(state[x] == false)
            ans[u].insert(dist(x, u));
        else {

            ans[u].erase(ans[u].find(dist(x, u)));
        }
    }
    state[x] = !state[x];
}

int get(int x) {
    int u = x, ret = INF;
    for(int u = x; u != -1; u = f[u]) {
        ret = min(ret, *ans[u].begin() + dist(x, u));
    }
    if(ret >= INF) ret = -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n, m; cin >> n;
    G = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    f[ decompose(1) ] = -1;
    pre(1, n);

    cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        if(a == 0) {
            update(b);
        } else {
            cout << get(b) << "\n";
        }
    }


}
