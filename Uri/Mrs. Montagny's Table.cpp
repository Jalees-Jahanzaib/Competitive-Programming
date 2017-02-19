#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 10000;
const int limit = 4e8;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int color[MAX];

vector<vector<int>> G;

bool go(int u, int c) {
    color[u] = c;

    for(auto &v : G[u]) {
        if(color[v] == -1) {
            if(!go(v, 1-c)) return false;
        } else {
            if(color[v] == c) return false;
        }

    }
    return true;
}

int cases;

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m) {
        G = vector<vector<int>> (n+1);
        for(int i = 0; i < m; i++)  {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        memset(color, -1, sizeof color);
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                ok &= go(i, 0);
            }
        }

        cout << "Instancia " << ++cases << "\n";
        if(ok) cout << "sim\n";
        else cout << "nao\n";
        cout << "\n";

    }

}
