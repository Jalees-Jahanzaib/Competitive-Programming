#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int MAX = 100010;
const int INF = INT_MAX;

int main() {
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);

    int n, m; scanf("%d %d", &n, &m);

    vector< vector<ii> > G(n+1);

    for(int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        G[a].push_back(ii(b, c));
        G[b].push_back(ii(a, c));
    }

    vector<int> d(n+1, INF);

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push(ii(0, 1));
    d[1] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        int w = q.top().first;
        q.pop();

        if(w != d[u]) continue;

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            int nd = G[u][i].second + w;
            if(d[v] > nd) {
                d[v] = nd;
                q.push( ii(nd, v) );
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i-1) printf(" ");
        printf("%d", d[i]);
    }
    printf("\n");



}
