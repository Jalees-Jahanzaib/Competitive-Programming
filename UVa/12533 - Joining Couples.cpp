#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100010
#define MAXLOG 20
#define INF (ll)(1e16)
#define ll long long
#define MOD 1000000007

using namespace std;

int n, A[MAX][MAXLOG], depth[MAX], cycle[MAX];
int father[MAX], node[MAX], id[MAX];
vector<vector<int>> G;

int find(int x) {
    return father[x] = x == father[x] ? x : find(father[x]);
}
bool merge(int x, int y) {
    if(find(x) == find(y)) return false;
    father[find(x)] = find(y);
    return true;
}

void init() {
    for(int i = 0; i <= n; i++) father[i] = i;
    memset(cycle, 0, sizeof cycle);
}

void go(int u, int p, int d) {
    depth[u] = d;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v != p && !cycle[v]) {
            go(v, u, d + 1);
            A[v][0] = u;
        }
    }
}

ii query(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    for(int j = MAXLOG-1; j >= 0; j--)
        if(depth[ A[a][j] ] >= depth[b])
            a = A[a][j];
    if(node[a] == node[b]) return ii(a, b);

    for(int j = MAXLOG-1; j >= 0; j--)
        if(node[ A[a][j] ] != node[ A[b][j] ]) {
            a = A[a][j];
            b = A[b][j];
        }

    return ii( A[a][0], A[b][0] );
}



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    while(cin >> n) {
        init();
        vector<int> next(n+1, -1);
        G = vector<vector<int>>(n+1);
        for(int i = 0; i < n; i++) {
            int to; cin >> to;
            if(!merge(i+1, to))
                cycle[i+1] = 1;
            next[i+1] = to;
            G[to].PB(i+1);
        }
        int tag = 1, tt = 1;
        for(int i = 1; i <= n; i++) {
            if(cycle[i] == 1) {
                int u = i, sz = 1;
                while(next[u] != i) sz++, u = next[u];
                u = i;
                do{
                    id[u] = tt++; node[u] = tag, u = next[u], cycle[u] = sz;
                }
                while(u != i);
                tag++;
            }
            else node[i] = tag++;
        }

        for(int i = 1; i <= n; i++) {
            if(cycle[i]) {
                go(i, -1, 0);
                A[i][0] = i;
            }
        }

        for(int j = 0; j < MAXLOG-1; j++)
            for(int i = 1; i <= n; i++)
                A[i][j+1] = A[ A[i][j] ][j];

        int q; cin >> q;
        while(q--) {
            int a, b; cin >> a >> b;
            ii lca = query(a, b);
            if(node[lca.first] != node[lca.second]) cout << "-1\n";
            else {
                if(!cycle[lca.first]) cout << depth[a] + depth[b] - 2*depth[lca.first] << "\n";
                else cout << depth[a] + depth[b] + min( abs(id[lca.first] - id[lca.second]), cycle[lca.first] - abs(id[lca.first] - id[lca.second]) ) << "\n";
            }
        }
    }
}

