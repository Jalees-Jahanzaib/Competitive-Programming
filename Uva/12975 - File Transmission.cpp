#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 10000 + 10
#define MAXLOG 15
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

vector< vector<ii> > G;
int n, m;
int id, disc[MAX], seen[MAX], low[MAX];
bool bridge[2 * MAX];

void bridges(int cur, int p) {
    disc[cur] = low[cur] = ++id;
    seen[cur] = true;

    for(int i = 0; i < G[cur].size(); i++) {
        int next = G[cur][i].first;
        int idx = G[cur][i].second;
        if(!seen[next]) {
            bridges(next, cur);
            low[cur] = min(low[cur], low[next]);

            if(low[next] > disc[cur]) {
                bridge[idx] = true;
            }
        }
        else if(next != p)
            low[cur] = min(low[cur], disc[next]);
    }
}

int dp[MAX][MAXLOG+10], label[MAX], N;
int depth[MAX];

void dfs1(int u, int idx) {
    seen[u] = true;
    label[u] = idx;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first;
        int edge = G[u][i].second;
        if(!seen[v] && !bridge[edge]) {
            dfs1(v, idx);
        }
    }
}

void dfs2(int u, int d) {
    seen[u] = true;
    depth[label[u]] = d;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first;
        int edge = G[u][i].second;
        if(!seen[v] && !bridge[edge]) {
            dfs2(v, d);
        }
        else if(!seen[v] && bridge[edge]) {
            dfs2(v, d + 1);
            dp[label[v]][0] = label[u];
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = MAXLOG-1; i >= 0; i--)
        if(depth[dp[a][i]] >= depth[b])
            a = dp[a][i];

    if(a == b) return a;

    for(int i = MAXLOG-1; i >= 0; i--)
        if(dp[a][i] != dp[b][i])
            a = dp[a][i],
            b = dp[b][i];

    return dp[a][0];
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin)

    bool first = true;
    while(cin >> n >> m && (n + m != 0)) {
        if(first) first = false;
        else cout << "\n";
        int f, t;
        G = vector< vector<ii> > (n + 1);
        for(int i = 0; i < m; i++) {
            cin >> f >> t;
            f--; t--;
            G[f].PB(ii(t, i));
            G[t].PB(ii(f, i));
        }

        id = 0;
        memset(seen, false, sizeof seen);
        memset(bridge, false, sizeof bridge);
        bridges(0, -1);

        memset(seen, false, sizeof seen);
        N = -1;
        for(int i = 0 ; i < n; i++) {
            if(!seen[i]) {
                N++;
                dfs1(i, N);
            }
        }

        memset(seen, false, sizeof seen);
        dp[0][0] = 0;
        dfs2(0, 0);

        for(int j = 0; j < MAXLOG; j++)
            for(int i = 0; i <= N; i++)
                dp[i][j + 1] = dp[dp[i][j]][j];



        cout << "Case #" << ++cases << ":\n";
        int q;
        cin >> q;

        int a, b;
        while(q--) {
            cin >> a >> b;
            a--; b--;
            a = label[a];
            b = label[b];

            cout << 50 * ((depth[a] + depth[b]) - 2*depth[lca(a, b)]) << "\n";
        }

    }

}
