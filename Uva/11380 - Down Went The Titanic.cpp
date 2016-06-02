#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 40
#define TAM 4000
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

char board[MAX][MAX];
int id[MAX][MAX], inv[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin)
    int R, C, P;

    while(cin >> R >> C >> P) {

        Network net(2*R*C + 2);



        int SINK = 2*R*C + 1, SOURCE = 2*R*C;

        int l = 0, r = R*C;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++) {
                cin >> board[i][j];
                if(board[i][j] != '~') {
                    if(board[i][j] == '*') net.addDirEdge(SOURCE, l, 1);
                    if(board[i][j] == '*' || board[i][j] == '.') net.addDirEdge(l, r, 1);
                    if(board[i][j] == '@' || board[i][j] == '#') net.addDirEdge(l, r, INF_CAP);
                    if(board[i][j] == '#') net.addDirEdge(r, SINK, P);
                    id[i][j] = l; l++;
                    inv[i][j] = r; r++;
                }
            }

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(board[i][j] != '~')
                    for(int dx = -1; dx <= 1; dx++)
                        for(int dy = -1; dy <= 1; dy++) {
                            if(abs(dx) + abs(dy) != 1) continue;
                            if(!(i + dx >= 0 && i + dx < R && j + dy >= 0 && j + dy < C)) continue;
                            if(board[i + dx][j + dy] == '~') continue;
                            int a = inv[i][j], b = id[i + dx][j + dy];
                            net.addDirEdge(a, b, INF_CAP);
                        }


        cout << net.maxFlow(SOURCE, SINK) << "\n";

    }

}
