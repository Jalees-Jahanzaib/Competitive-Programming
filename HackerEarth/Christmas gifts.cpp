#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair< int, int> ii;

const int MOD = 1000000007;
const int MAX = 200010;
const ll INF = LLONG_MAX/2;

bool seen[MAX];

void go(int u, int c, vector<int> &color, vector<vector<int>> &G) {
    color[u] = c;
    seen[u] = true;
    if(c == 1) {
        for(auto &v : G[u]) {
            color[v] = 0;
        }
        for(auto &v : G[u]) {
            if(!seen[v]) {
                go(v, 0, color, G);
            }
        }

    } else {
        for(auto &v : G[u]) {
            if(color[v] == -1) {
                color[v] = 1;
                go(v, 1, color, G);
            }
            if(!seen[v]) {
                go(v, color[v], color, G);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector< vector<int> > G(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> color(n+1, -1);

    go(1, 1, color, G);

    for(int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

}
