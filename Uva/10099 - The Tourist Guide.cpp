#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100100 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

vector< vector<ii> > G;
int n, m, s, t, g;
int d[200];

int dijkstra() {
    priority_queue<ii> q;
    q.push(ii(INF, s));
    d[s] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        int best = q.top().first;
        q.pop();

        if(d[u] > best) continue;

        //cout << u << " - " << best << endl;

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            int edge = min(best, G[u][i].second);
            if(d[v] < edge) {
                q.push(ii(edge, v));
                d[v] = edge;
            }
        }
    }

    return d[t];
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    while(cin >> n >> m && (n + m != 0)) {
        memset(d, false, sizeof d);
        G = vector< vector<ii> > (n + 2);

        int a, b, c;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            G[a].PB(ii(b, c));
            G[b].PB(ii(a, c));
        }
        cin >> s >> t >> g;

        int ans = dijkstra();

        //cout << "ans = " << ans << endl;

        int realAns = 0;
        while(g > 0) {
            realAns++;
            g -= (ans - 1);
        }

        if(s == t) realAns = 1;

        cout << "Scenario #" << ++cases << "\n";
        cout << "Minimum Number of Trips = " << realAns << "\n\n";

    }

}
