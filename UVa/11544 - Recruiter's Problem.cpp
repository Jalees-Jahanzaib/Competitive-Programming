#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 105;
const double EPS = 1e-5;
const int INF = INT_MAX;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

typedef int LL;

struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
			from(from), to(to), cap(cap), flow(flow), index(index) {
	}
};
struct Network {
	int N;
	vector<vector<Edge> > G;
	vector<LL> excess;
	vector<int> dist, active, count;
	queue<int> Q;

	Network(int N) :
			N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {
	}

    void init() {
        for(int i = 0; i < N; i++) {
            excess[i] = dist[i] = active[i] = count[i] = count[i+N] = 0;
            for(int j = 0; j < G[i].size(); j++) {
                G[i][j].flow = 0;
            }
        }
    }

	void add_edge(int from, int to, int cap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to)
			G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	void Enqueue(int v) {
		if (!active[v] && excess[v] > 0) {
			active[v] = true;
			Q.push(v);
		}
	}

	void Push(Edge &e) {
		int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
		if (dist[e.from] <= dist[e.to] || amt == 0)
			return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		Enqueue(e.to);
	}

	void Gap(int k) {
		for (int v = 0; v < N; v++) {
			if (dist[v] < k)
				continue;
			count[dist[v]]--;
			dist[v] = max(dist[v], N + 1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}

	void Relabel(int v) {
		count[dist[v]]--;
		dist[v] = 2 * N;
		for (int i = 0; i < G[v].size(); i++)
			if (G[v][i].cap - G[v][i].flow > 0)
				dist[v] = min(dist[v], dist[G[v][i].to] + 1);
		count[dist[v]]++;
		Enqueue(v);
	}
	void Discharge(int v) {
		for (int i = 0; excess[v] > 0 && i < G[v].size(); i++)
			Push(G[v][i]);
		if (excess[v] > 0) {
			if (count[dist[v]] == 1)
				Gap(dist[v]);
			else
				Relabel(v);
		}
	}

	LL max_flow(int s, int t) {
		count[0] = N - 1;
		count[N] = 1;
		dist[s] = N;
		active[s] = active[t] = true;
		for (int i = 0; i < G[s].size(); i++) {
			excess[s] += G[s][i].cap;
			Push(G[s][i]);
		}
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			active[v] = false;
			Discharge(v);
		}
		LL totflow = 0;
		for (int i = 0; i < G[s].size(); i++)
			totflow += G[s][i].flow;
		return totflow;
	}
};

int SOURCE, SINK;

void add_from_source(int n, Network &net) {
    for(int i = 1; i <= n; i++)
        net.add_edge(SOURCE, i, 1);
}

void add_to_sink(int n, int m, vector<int> &x, Network &net) {
    for(int i = 1; i <= m; i++) {
        net.add_edge(n+i, SINK, x[i]);
    }
}

void add_bipartite(int n, vector<vector<int>> &b, Network &net) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < b[i].size(); j++) {
            net.add_edge(i, b[i][j], 1);
        }
    }
}

int cases;

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> to_sink(m+1);
        for(int i = 1; i <= m; i++) {
            cin >> to_sink[i];
        }
        vector< vector<int> > bipartite(n+1);
        for(int i = 1; i <= n; i++) {
            int k; cin >> k;
            for(int j = 0; j < k; j++) {
                int x; cin >> x;
                bipartite[i].push_back(n+x);
            }
        }
        Network net(n+m+10);
        SOURCE = 0; SINK = (n+m+5);
        add_from_source(n, net);
        add_to_sink(n, m, to_sink, net);
        add_bipartite(n, bipartite, net);

        int ans = net.max_flow(SOURCE, SINK);
        cout << "Case #" << ++cases << ":\n";
        cout << ans << " applicant(s) can be hired.\n";
        vector<int> ret(n+1, -1);
        for(int i = 1; i <= n; i++) {
            net.G[0][i-1].cap = 0;
            for(int j = 0; j < bipartite[i].size(); j++) {
                int v = bipartite[i][j];
                if(net.G[v][0].cap <= 0) continue;
                net.init();
                net.G[v][0].cap--;
                int nflow = net.max_flow(SOURCE, SINK);
                if(nflow+1 == ans) {
                    ret[i] = v;
                    ans--;
                    break;
                }
                net.G[v][0].cap++;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(ret[i] != -1) {
                cout << i << " " << ret[i]-n << "\n";
            }
        }
    }
}
