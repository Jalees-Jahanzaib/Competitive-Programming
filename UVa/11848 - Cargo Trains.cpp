#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<double, int> ii;

const int INF = INT_MAX/3;
const int MAX = 102;

int ga[MAX][MAX], gb[MAX][MAX];
int n;

int spfa(double a ) {
    vector<double> d(n, 1e10);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    vector<bool> in(n);
    while(q.size()) {
        int u = q.front(); q.pop();

        in[u] = false;

        for(int v = 0; v < n; v++) {
            double nw;
            if(ga[u][v] == INF && gb[u][v] == INF) continue;
            if(ga[u][v] != INF && gb[u][v] != INF) {
                nw = a*ga[u][v] + (1-a)*gb[u][v];
            }
            else {
                nw = (ga[u][v] != INF ? ga[u][v] : gb[u][v]);
            }

            if(d[v] > nw + d[u]) {
                d[v] = nw + d[u];

                if(!in[v]) {
                    in[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return d[n-1];
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

    int ma, mb, q;
    while(cin >> n >> ma >> mb >> q && n != -1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ga[i][j] = gb[i][j] = INF;
            }
        }
        for(int i = 0; i < ma; i++) {
            int a, b, c; cin >> a >> b >> c;
            ga[a][b] = ga[b][a] = c;
        }
        for(int i = 0; i < mb; i++) {
            int a, b, c; cin >> a >> b >> c;
            gb[a][b] = gb[b][a] = c;
        }

        while(q--) {
            double a; cin >> a;
            cout << spfa(a) << endl;
        }
    }

}
