#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e4 + 10;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

vector<vector<int>> g;
bool seen[MAX], cycle[MAX];
bool ans;

void go(int u) {
    seen[u] = true;
    cycle[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(cycle[v]) ans = false;
        else if(!seen[v])go(v);
    }
    cycle[u] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        memset(seen, false, sizeof seen);
        int n, m; cin >> n >> m;
        g = vector<vector<int>>(n+1);
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
        }

        ans = true;
        for(int i = 1; i <= n; i++) {
            if(!seen[i]) {
                go(i);
            }
        }

        if(ans) cout << "NAO\n";
        else cout << "SIM\n";
    }
}
