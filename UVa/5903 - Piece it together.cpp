#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const int INF = INT_MAX;
const ll MAX = 1000;
const ll MOD = 1e9 + 7;

int DX[] = {-1, 1, 0, 0};
int DY[] = {0, 0, 1, -1};

vector< vector<int> > G;
bool seen[2*MAX*MAX];
int R[2*MAX*MAX], L[2*MAX*MAX];
int c, v; // Nodos izquierda, derecha

bool dfs(int node) {
	if (seen[node])
		return false;
	seen[node] = true;
	for (int i = 0; i < G[node].size(); i++) {
		int next = G[node][i];
		if (R[next] == -1 || dfs(R[next])) {
			R[next] = node;
			L[node] = next;
			return true;
		}
	}
	return false;
}
int maxBipartiteMatching() {
	int ans = 0;
	memset(R, -1, sizeof(R));
	memset(L, -1, sizeof(L));
	bool path;
	do {
		path = false;
		memset(seen, false, sizeof(seen));
		for (int i = 0; i < c; i++) {
			if (L[i] == -1 && !seen[i])
				if (dfs(i)) {
					path = true;
					ans++;
				}
		}
	} while (path);
	return ans;
}

string board[MAX];
int id[MAX][MAX];

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int tag = 0;
        for(int i = 0; i < n; i++) {
            cin >> board[i];
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'B') {
                    id[i][j] = tag;
                    ++tag;
                }

            }
        }
        int nodes = tag;
        tag += tag;
        c = tag;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'W') {
                    id[i][j] = tag;
                    ++tag;
                }

            }
        }

        G = vector<vector<int>> (2*tag+10);

        int cntw = 0, cntb = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'B') {
                    cntb++;
                    int id_b = id[i][j];
                    for(int k = 0; k < 2; k++) {
                        int nx = i + DX[k];
                        int ny = j + DY[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'W') {
                            int id1 = id[nx][ny];
                            G[id_b].push_back(id1);
                       }
                    }
                    for(int k = 2; k < 4; k++) {
                        int nx = i + DX[k];
                        int ny = j + DY[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'W') {
                            int id1 = id[nx][ny];
                            G[id_b+nodes].push_back(id1);
                        }
                    }
                } else if(board[i][j] == 'W'){
                    cntw++;
                }
            }
        }
        int ans = maxBipartiteMatching();
        if(ans == 2*cntb && ans == cntw) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}
