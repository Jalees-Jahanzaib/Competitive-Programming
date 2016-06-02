#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define TAM 2000
#define MAXLOG 15
#define INF INT_MAX / 3
#define INF_CAP INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

struct Edge {
	int to, cap, invIdx;
	Edge ( ) { }
	Edge(int to, int cap, int invIdx) :
		to(to), cap(cap), invIdx(invIdx) { }
};

struct Network {

	vector< vector<Edge> > G;
	int from[TAM], n;
	bool color[TAM];

	Network(int _n) : G(_n), n(_n) {
        //memset ( color, false, sizeof color);
	}


	// Call flood (source) to color one node
	// component of min cut.
/*	void flood ( int node ) {
		if ( color[node] ) return;
		color[node] = true;
		for ( const Edge& e : G[node] )
			if ( e.cap > 0 )
				flood ( e.to );
	}
*/
	int maxFlow ( int A, int B )
	{
		int flow = 0;
		while ( 1 ) {
			memset ( from, -1, sizeof(from) );

			queue<int> q;
			q.push ( A );
			from[A] = -2;
			for ( int i; !q.empty(); q.pop() ) {
				i = q.front();
				for ( Edge& e : G[i] )
					if ( from[e.to] == -1 && e.cap ) {
						from[e.to] = e.invIdx;
						q.push ( e.to );
					}
			}

			if ( from[B] == -1 ) break;

			int aug = INF_CAP;
			for ( int i = B, j; i != A; i = j ) {
				j = G[i][from[i]].to;
				aug = min ( aug, G[j][ G[i][from[i]].invIdx ].cap );
			}

			for ( int i = B, j; i != A; i = j ) {
				j = G[i][from[i]].to;
				G[j][ G[i][from[i]].invIdx ].cap -= aug;
				G[i][from[i]].cap += aug;
			}

			flow += aug;
		}

		return flow;
	}

	void addNonDirEdge ( int a, int b, int c ) {
		//assert ( a != b );
		G[a].push_back ( Edge(b,c,G[b].size()) );
		G[b].push_back ( Edge(a,c,G[a].size()-1) );
	}

	void addDirEdge ( int a, int b, int c ) {
		//assert ( a != b );
		G[a].push_back ( Edge(b,c,G[b].size()) );
		G[b].push_back ( Edge(a,0,G[a].size()-1) );
	}

};

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin)

    int n, m;

    while(cin >> n >> m && (n + m != 0)) {
        int c[n], SOURCE = n + m + 1, SINK = n + m, target = 0;
        for(int i = 0; i < n; i++) cin >> c[i], target += c[i];
        Network net(n + m + 3);

        for(int i = 0; i < m; i++) net.addDirEdge(SOURCE, i, 1);
        for(int i = m, j = 0; i < SINK; i++, j++) net.addDirEdge(i, SINK, c[j]);
        for(int i = 0; i < m; i++) {
            int cant, t;
            cin >> cant;
            for(int j = 0; j < cant; j++) {
                cin >> t;
                net.addDirEdge(i, m + t - 1, INF_CAP);
            }
        }

        /*for(int i = 0; i < n + m + 2; i++) {
            cout << i << " -> ";
            for(int j = 0; j < net.G[i].size(); j++) {
                cout << net.G[i][j].to << " ";
            }
            cout << endl;
        }*/

        //cout << net.maxFlow(SOURCE, SINK) << endl;

        if(net.maxFlow(SOURCE, SINK) == target) {
            cout << "1\n";
            for(int i = m; i < SINK; i++) {
                bool first = true;
                for(int j = 0; j < net.G[i].size(); j++) {
                    if(!(net.G[i][j].to >= 0 && net.G[i][j].to < m)) continue;
                    if(net.G[i][j].cap > 0) {
                        if(!first) cout << " ";
                        cout << net.G[i][j].to + 1;
                        first = false;
                    }
                }
                cout << "\n";
            }

        }
        else {
            cout << "0\n";
        }
    }

}
