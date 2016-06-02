#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 10000 + 10
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
	int from[MAX], n;
	bool color[MAX];

	Network(int _n) {
		n = _n;
		memset ( color, false, n );
        G = vector< vector<Edge> >(n);
	}

	// Call flood (source) to color one node
	// component of min cut.
	void flood ( int node ) {
		if ( color[node] ) return;
		color[node] = true;
		for ( const Edge& e : G[node] )
			if ( e.cap > 0 )
				flood ( e.to );
	}

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
				//cout << i << "-";
			}
			//cout << endl;

			flow += aug;
		}

		return flow;
	}

	void addNonDirEdge ( int a, int b, int c ) {
		assert ( a != b );
		G[a].push_back ( Edge(b,c,G[b].size()) );
		G[b].push_back ( Edge(a,c,G[a].size()-1) );
	}

	void addDirEdge ( int a, int b, int c ) {
		assert ( a != b );
		G[a].push_back ( Edge(b,c,G[b].size()) );
		G[b].push_back ( Edge(a,0,G[a].size()-1) );
	}

};


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.txt", "r", stdin)
    int SINK = 38, SOURCE = 37;
    Network net = Network(40);;
    string line;
    while(getline(cin, line)) {
        int all = 0;
        net = Network(40);

        istringstream ss(line);
        string left, right;
        ss >> left >> right;
        int from = left[0] - 'A', c = left[1] - '0';
        all += c;

        net.addDirEdge(SOURCE, from, c);
        for(int i = 0; i < right.size() - 1; i++) {
            net.addDirEdge(from, (26) + (right[i] - '0'), 1);
        }

        while(getline(cin, line) && line != "") {
            istringstream ss1(line);
            ss1 >> left >> right;
            from = left[0] - 'A', c = left[1] - '0';
            all += c;

            net.addDirEdge(SOURCE, from, c);
            for(int i = 0; i < right.size() - 1; i++) {
                net.addDirEdge(from, (26) + (right[i] - '0'), 1);
            }
        }

        for(int i = 26; i < 36; i++) {
            net.addDirEdge(i, SINK, 1);
        }
        //cout << net.maxFlow(SOURCE, SINK)  << endl;
        if(net.maxFlow(SOURCE, SINK) == all) {
            for(int i = 26; i <= 35; i++) {
                int found = false;
                for(int j = 0; j < net.G[i].size(); j++) {
                    if(net.G[i][j].to == SINK) continue;
                    //cout << i << " " << net.G[i][j].to << endl;
                    if(net.G[i][j].cap == 1) {
                        cout << char(net.G[i][j].to + 'A');
                        found = true;
                        break;
                    }
                }
                if(!found) cout << "_";
                cout << endl;
            }
            cout << "\n";
        }
        else {
            cout << "!\n";
        }
    }

}
