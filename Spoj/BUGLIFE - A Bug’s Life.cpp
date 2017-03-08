#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 100010;
const ll MOD = 1e9 + 7;

struct sat2 {
    vector< vector<int> > g, rg;
    vector<int> component;
    vector<bool> ans;
    int tag, n, sz;
    stack<int> st;
    sat2(int n) : n(n), sz(2*n), g(vector< vector<int> >(2*n)), rg(vector< vector<int> >(2*n)) {}
    void add_edge(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	int neg(int u) {
	    return (n+u)%sz;
    }
	void implication(int u, int v) {
		add_edge(neg(u), v);
	}
	void add(int u, int v) { /// u or v
		implication(u, v);
		implication(v, u);
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
    bool satisfiable() {
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
            if(component[i] == component[neg(i)]) return false;
            ans[i] = component[i] > component[neg(i)];
        }
        return true;
    }
};

int cases;

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        sat2 sat(n);
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            --a, --b;
            sat.add(a, b);
            sat.add(sat.neg(a), sat.neg(b));
        }

        cout << "Scenario #" << ++cases << ":\n";
        if(!sat.solve()) cout << "Suspicious bugs found!\n";
        else cout << "No suspicious bugs found!\n";
    }
}
