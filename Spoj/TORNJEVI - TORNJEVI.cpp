#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 105;
const double EPS = 1e-5;
const int INF = INT_MAX;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};


struct sat2 {
    vector< vector<int> > g, rg;
    vector<int> component;
    vector<bool> ans;
    int tag, n, sz;
    stack<int> st;
    sat2(int n) : n(n), sz(2*n), g(vector< vector<int> >(2*n)), rg(vector<vector<int>>(2*n)) {}
    void add_edge(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	int neg(int u) {
	    return (n+u)%sz;
    }
	void implication(int u, int v) { /// to add (u or v)
		add_edge(neg(u), v);
		add_edge(neg(v), u);
	}
	void diff(int u, int v) {
        implication(u, v);
        implication(neg(u), neg(v));
	}
	void eq(int u, int v) {
        diff(neg(u), v);
	}
    void dfs(int u, vector< vector<int> > &g, bool first) {
        component[u] = tag;
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(component[v] == -1)
                dfs(v, g, first);
        }
        if(first) st.push(u);
    }
    bool possible() {
        tag = 0;
        ans = vector<bool>(n);
        component = vector<int>(sz, -1);
        for(int i = 0; i < sz; i++) {
            if(component[i] == -1)
                dfs(i, g, true);
        }
        component = vector<int>(sz, -1);
        tag = 0;
        while(st.size()) {
            int u = st.top(); st.pop();
            if(component[u] != -1) continue;
            ++tag;
            dfs(u, rg, false);
        }
        for(int i = 0; i < n; i++) {
            if(component[i] == component[neg(i)])
                 return false;
            ans[i] = component[i] > component[neg(i)];
        }
        return true;
    }
};

string board[MAX];
int id[MAX][MAX];
vector<int> p[MAX][MAX];
int n, m;

bool search_from_T(int i, int j, int dir, int id_t) {
    int x = i, y = j;
    i += DX[dir]; j += DY[dir];
    while(i >= 0 && i < n && j >= 0 && j < m && board[i][j] != 'T' && board[i][j] != '#') {
        p[i][j].push_back(id_t);
        i += DX[dir]; j += DY[dir];
    }

    if(!(i >= 0 && i < n && j >= 0 && j < m)) return false;
    if(board[i][j] == 'T') {
        i = x + DX[dir]; j = y + DY[dir];
        while(i >= 0 && i < n && j >= 0 && j < m && board[i][j] != 'T' && board[i][j] != '#') {
            p[i][j].pop_back();
            i += DX[dir]; j += DY[dir];
        }
    }
    return board[i][j] == 'T';
}

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

    cin >> n >> m;
    int t = 0;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'T')
                id[i][j] = t++;
        }
    }

    sat2 sat(2*t);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'T') {
                if(search_from_T(i, j, 0, id[i][j])) {
                    sat.implication(sat.neg(id[i][j]), sat.neg(id[i][j]));
                }
                if(search_from_T(i, j, 1, sat.neg(id[i][j]))) {
                    sat.implication(id[i][j], id[i][j]);
                }
                if(search_from_T(i, j, 2, t+id[i][j])) {
                    sat.implication(sat.neg(t+id[i][j]), sat.neg(t+id[i][j]));
                }
                if(search_from_T(i, j, 3, sat.neg(t+id[i][j]))) {
                    sat.implication(t+id[i][j], t+id[i][j]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'n') {
                if(p[i][j].size() == 1) {
                    sat.implication(p[i][j][0], p[i][j][0]);
                } else {
                    sat.implication(p[i][j][0], p[i][j][1]);
                }
            }
        }
    }

    sat.possible();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'T') {
                int x = sat.ans[ id[i][j] ];
                int y = sat.ans[ t+id[i][j] ];
                if(x && y) {
                    cout << '3';
                } else if(x && !y) {
                    cout << '4';
                } else if(!x && y) {
                    cout << '2';
                } else {
                    cout << '1';
                }
            } else {
                cout << board[i][j];
            }
        }
        cout << "\n";
    }



}
