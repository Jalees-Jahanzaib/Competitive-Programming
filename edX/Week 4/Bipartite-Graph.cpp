#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 100010;

int color[MAX];
vector< vector<int> > G;

bool go(int u, int c) {
    color[u] = c;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(color[v] == -1)
            if( !go(v, 1-c) )
                return false;
        if(color[v] != 1-c) return false;
    }

    return true;
}

int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);

    int n, m; cin >> n >> m;

    for(int i = 0; i <= n+1; i++) color[i] = -1;

    G = vector< vector<int> > (n+1);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool ans = true;
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1)
            ans &= go(i, 0);
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";


}
