#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

typedef vector<vector<int>> graph;

const int MAX = 600;
int ages[MAX];

int tag;
int seen[MAX];
int id[MAX];

int go (int u, graph &g) {
    seen[u] = tag;
    int ans = ages[u];
    for (auto &v : g[u]) {
        if (seen[v] != tag) {
            ans = min(ans, go(v, g));
        }
    }
    return ans;
}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif

    int n, m, q;
    while (cin >> n >> m >> q) {
        graph g(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> ages[i];
            id[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            g[v].push_back(u);
        }

        char cmd;
        int a, b;
        while (q--) {
            cin >> cmd;
            if (cmd == 'T') {
                cin >> a >> b;
                swap(id[a], id[b]);
                swap(ages[id[a]], ages[id[b]]);
            } else {
                cin >> a;
                a = id[a];
                ++tag;
                int temp = ages[a];
                ages[a] = INT_MAX;
                if (g[a].size() == 0) cout << '*' << '\n';
                else cout << go(a, g) << '\n';
                ages[a] = temp;
            }
        }
    }
}
