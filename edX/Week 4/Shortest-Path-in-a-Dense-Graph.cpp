#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAX = 100010;
const ll INF = LLONG_MAX;

int main() {
    freopen("dense.in", "r", stdin);
    freopen("dense.out", "w", stdout);

    int n, s, f; scanf("%d %d %d", &n, &s, &f);

    vector< vector<ii> > G(n+1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int c; scanf("%d", &c);
            if(c == -1) continue;
            if(i == j) continue;
            G[i].push_back(ii(j, c));
        }
    }

    vector<ll> d(n+1, INF);

    priority_queue< ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, s));
    d[s] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        ll w = q.top().first;
        q.pop();

        if(w != d[u]) continue;
        if(u == f) break;

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            ll nd = G[u][i].second + w;
            if(d[v] > nd) {
                d[v] = nd;
                q.push( ii(nd, v) );
            }
        }
    }

    if(d[f] == INF) printf("-1");
    else printf("%lld", d[f]);
    printf("\n");



}
