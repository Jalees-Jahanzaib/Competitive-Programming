#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define TAM 100 + 10
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

    int SINK, SOURCE, shirts, volunteers, nTest;

    cin >> nTest;
    while(nTest--) {
        cin >> shirts >> volunteers;

        Network net(shirts + volunteers + 10);
        SOURCE = shirts + volunteers + 1;
        SINK = shirts + volunteers + 2;
        int c = shirts / 6;

        map<string, int> id;
        string a, b;
        int idx = volunteers;
        for(int i = 0; i < volunteers; i++) {
            cin >> a >> b;
            if(!id.count(a)) {
                id[a] = idx; idx++;
                net.addDirEdge(SOURCE, id[a], c);
            }
            if(!id.count(b)) {
                id[b] = idx; idx++;
                net.addDirEdge(SOURCE, id[b], c);
            }

            net.addDirEdge(id[a], i, 1);
            net.addDirEdge(id[b], i, 1);
            net.addDirEdge(i, SINK, 1);
        }

        if(net.maxFlow(SOURCE, SINK) == volunteers) cout << "YES\n";
        else cout << "NO\n";

    }

}
