
#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;
//typedef pair<ll, ll> ii;
//typedef pair<ii, ii> iiii;
//
const ll INF = LLONG_MAX/4;
//const int MAX = 70001;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

typedef pair<ll, ll> ii;
const int MAXE = 100000, MAXN = 100000;
struct edge { int u, v; ll cost, cap, flow; } E[MAXE];

struct Network {
    edge *pred[MAXN];
    vector< vector<edge *> > g;
    ll d[MAXN], phi[MAXN];
    int N, EE;
    Network(int n) {
        N = n+10;
        EE = 0;
        g = vector< vector<edge *> > (N);
    }

    inline edge * opp(edge * e) { return E + ((e - E) ^ 1); }

    void add_edge(int u, int v, int cost, int cap) {
      E[EE] = { u, v, cost, cap, 0 };
      g[u].emplace_back(E + (EE++));
      E[EE] = { v, u, -cost, 0, 0 };
      g[v].emplace_back(E + (EE++));
    }

    bool dijkstra(int S, int T) {
      fill(d, d + N, INF);
      fill(pred, pred + N, nullptr);
      priority_queue< ii, vector<ii>, greater<ii> > pq;
      d[S] = 0;
      for (pq.emplace(d[S], S); !pq.empty(); ) {
        int u = pq.top().second; pq.pop();
        for (auto e : g[u]) {
          if (e->cap - e->flow > 0 && d[e->v] > d[e->u] + e->cost + phi[e->u] - phi[e->v]) {
            d[e->v] = d[e->u] + e->cost + phi[e->u] - phi[e->v];
            pred[e->v] = e;
            pq.emplace(d[e->v], e->v);
          }
        }
      }
      for(int i = 0; i < N; i++) phi[i] = min(INF, phi[i] + d[i]);
      return d[T] != INF;
    }

    pair<ll, ll> mincost_maxflow(int S, int T) {
      ll mincost = 0, maxflow = 0;
      fill(phi, phi + N, 0);
      while (dijkstra(S, T)) {
        ll flow = INF;
        for (edge * e = pred[T]; e; e = pred[e->u])
          flow = min(flow, e->cap - e->flow);
        for (edge * e = pred[T]; e; e = pred[e->u]) {
          mincost += e->cost * flow;
          e->flow += flow;
          opp(e)->flow -= flow;
        }
        maxflow += flow;
      }
      return make_pair(mincost, maxflow);
    }
};

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        vector<ll> all(3*m);
        for(int i = 0; i < 3*m; i += 3) {
            cin >> all[i] >> all[i+1] >> all[i+2];
        }
        ll flow, cap; cin >> flow >> cap;
//        cout << " cap = " << cap << endl;
        Network net(n+4);
        int SOURCE = 0;
        net.add_edge(SOURCE, 1, 0, flow);
        for(int i = 0; i < all.size(); i += 3) {
            net.add_edge(all[i], all[i+1], all[i+2], cap);
            net.add_edge(all[i+1], all[i], all[i+2], cap);
        }
        ii ans = net.mincost_maxflow(SOURCE, n);
//        cout << ans.first <<  " - " << ans.second << endl;
        if(ans.second == flow) cout << ans.first << "\n";
        else cout << "Impossible.\n";
    }

}
