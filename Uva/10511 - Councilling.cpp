#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, string>
#define MAX 100 + 10
#define TAM 78000 + 10
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
        memset ( color, false, sizeof color);
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

int main() {
    ios_base::sync_with_stdio(0);
    /*  cin.tie(0);
    cout.tie(0);*/
    //freopen("input.txt", "r", stdin)

    bool first = true;

    string line, name, party, club;
    getline(cin, line);
    getline(cin, line);
    while(!cin.eof()) {
        Network net(TAM);
        int SOURCE = 0, SINK = TAM - 2, idxName = 1, idxParty = 1001, idxClub = 2001;
        map<string, int> idName, idParty, idClub;
        map<int, string> ID;

        //for(int i = 1; i <= 1000; i++) net.addDirEdge(SOURCE, i, 1);

        while(getline(cin, line) && line != "") {
            istringstream ss(line);
            ss >> name >> party;
            if(!idName.count(name)) idName[name] = idxName, ID[idxName] = name, idxName++;
            if(!idParty.count(party)) idParty[party] = idxParty, ID[idxParty] = party, idxParty++;

            net.addDirEdge(idName[name], idParty[party], 1);

            while(ss >> club) {
                if(!idClub.count(club)) idClub[club] = idxClub, ID[idxClub] = club, idxClub++;
                int r = idClub[club];

                net.addDirEdge(r, idName[name], 1);
            }
        }

        int x = idClub.size();
        for(int i = 2001; i < idxClub; i++) net.addDirEdge(SOURCE, i, 1);
        for(int i = 1001; i < idxParty; i++) net.addDirEdge(i, SINK, (x - 1) / 2);

        if(first) first = false;
        else cout << "\n";

        if(net.maxFlow(SOURCE, SINK) == x) {
            for(int i = 2001; i < idxClub; i++) { ///Clubes
                for(int j = 0; j < net.G[i].size(); j++) { ///Personas
                    if(net.G[i][j].to == SOURCE) continue;
                    if(net.G[i][j].cap == 0) {
                        int v = net.G[i][j].to;
                        cout << ID[v] << " " << ID[i] << "\n";
                    }
                }
            }
        }
        else {
            cout << "Impossible.\n";
        }
    }

}
