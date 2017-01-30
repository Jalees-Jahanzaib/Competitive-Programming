#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAX = 100010;
const ll INF = LLONG_MAX - 3000000000000000010;
const ll limit_down = -5000000000000000010;

struct edge {
    int a, b; ll c;
    edge() {}
    edge(int a, int b, ll c) : a(a), b(b), c(c) {}
};

int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

//    cout << limit_down << endl;

    int n, m, s; scanf("%d %d %d", &n, &m, &s);


    vector< edge > all(m);
    vector<vector<int>> G(n+1);
    for(int i = 0; i < all.size(); i++) {
        scanf("%d %d %lld", &all[i].a, &all[i].b, &all[i].c);
        G[ all[i].a ].push_back( all[i].b );

    }

    vector<ll> d(n+1, INF);
    vector<bool> done(n+1, false);
    d[s] = 0;
    done[s] = true;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < all.size(); j++) {
            int u = all[j].a, v = all[j].b; ll c = all[j].c;
            if(d[u] != INF && d[v] > d[u] + c) {
                d[v] = max(limit_down, d[u] + c);
            }
        }
    }
    vector<bool> cycle(n+1, false);
    for(int j = 0; j < all.size(); j++) {
        int u = all[j].a, v = all[j].b; ll c = all[j].c;
        if(d[u] != INF && d[v] > d[u] + c) {
            queue<int> q;
            q.push(u);
            cycle[u] = true;
            while(!q.empty()) {
                u = q.front(); q.pop();

                for(int i = 0; i < G[u].size(); i++) {
                    v = G[u][i];
                    if(!cycle[v]) {
                        cycle[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(d[i] == INF) printf("*\n");
        else if(cycle[i]) printf("-\n");
        else printf("%lld\n", d[i]);
    }




}
