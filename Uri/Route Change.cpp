#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 400000;
const ll MOD = 1e9 + 7;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n, m, c, k;
    while(cin >> n >> m >> c >> k && (n+m+k+c) != 0) {
        vector<vector<ii>> G(n+1);
        vector<vector<ii>> G2(n+1);
        for(int i = 0; i < m; i++) {
            int a, b, p; cin >> a >> b >> p;
            if(a <= c-1 && b <= c-1) {
                G2[a].push_back(ii(b, p));
                G2[b].push_back(ii(a, p));
            } else {
                G[a].push_back(ii(b, p));
                G[b].push_back(ii(a, p));
            }
        }

        vector<int> mindist_c(n+1, INF);
        mindist_c[c-1] = 0;
        for(int i = c-1; i > 0; i--) {
            for(auto &x : G2[i]) {
                if(x.first == i-1)
                    mindist_c[ i-1 ] = min(mindist_c[i-1], x.second + mindist_c[i]);
            }
        }

        vector<int> d(n+1, INF);
        priority_queue<ii, vector<ii>, greater<ii>> q;
        d[k] = 0;
        q.push(ii(0, k));
        while(!q.empty()) {
            int u = q.top().second;
            int w = q.top().first;
            q.pop();

            if(d[u] != w) continue;
            if(u <= c-1) continue;

            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i].first;
                int nw = G[u][i].second + w;

                if(d[v] > nw) {
                    d[v] = nw;
                    q.push(ii(nw, v));
                }
            }
        }

        ll ans = INF;
        for(int i = 0; i < c; i++) {
            ans = min(ans, (ll)(mindist_c[i]) + (ll)(d[i]));
        }

        cout << ans << "\n";
    }

}
