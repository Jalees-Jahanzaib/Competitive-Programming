#include<bits/stdc++.h>

#define MAX 1010
#define ii pair<int, int>
#define INF INT_MAX/2

using namespace std;

int n, m, b, p;
vector< vector<ii> > G;
bool bank[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m >> b >> p) {
        memset(bank, false, sizeof bank);
        G = vector< vector<ii> >(n+1);
        int a, x, c;
        for(int i = 0; i < m; i++) {
            cin >> a >> x >> c;
            G[a].push_back(ii(x, c));
            G[x].push_back(ii(a, c));
        }

        priority_queue< ii, vector<ii>, greater<ii> > q;
        for(int i = 0; i < b; i++) {
            cin >> a;
            bank[a] = true;
        }
        vector<int> d(n+1, INF);
        for(int i = 0; i < p; i++) {
            cin >> a;
            d[a] = 0;
            q.push(ii(0, a));
        }
        while(!q.empty()) {
            int cost = q.top().first;
            int u = q.top().second;
            q.pop();

            if(d[u] != cost) continue;

            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i].first;
                int ncost = G[u][i].second + cost;
                if(d[v] > ncost) {
                    d[v] = ncost;
                    q.push(ii(ncost, v));
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(bank[i])
                ans = max(ans, d[i]);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(d[i] == ans && bank[i])
                cnt++;
        }

        if(ans == INF) cout << cnt << " *\n";
        else cout << cnt << " " << ans << "\n";
        bool first = true;
        for(int i = 0; i < n; i++) {
            if(d[i] == ans && bank[i]) {
                if(!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << "\n";


    }
}
