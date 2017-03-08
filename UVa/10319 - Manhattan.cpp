#include <bits/stdc++.h>

using namespace std;

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
            if(component[i] == component[neg(i)]) return false;
            ans[i] = component[i] > component[neg(i)];
        }
        return true;
    }
};

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t, m;
    cin >> t;
    while (t--) {
    	int s, a; cin >> s >> a >> m;
    	int s1, a1, s2, a2;

    	sat2 sat(s + a);
    	for (int i = 0; i < m; ++i) {
    		cin >> s1 >> a1 >> s2 >> a2;

    		a1 += s; a2 += s;
    		int p, q, r, s;

    		if (s1 == s2) {
    			if (a1 < a2) sat.implication(s1, s1);
    			else	     sat.implication(sat.neg(s1), sat.neg(s1));
    			continue;
    		} else if (a1 == a2) {
    			if (s1 < s2) sat.implication(sat.neg(a1), sat.neg(a1));
    			else 	     sat.implication(a1, a1);
    			continue;
    		} else if (s1 < s2) {
    			if (a1 < a2) p = s1, q = sat.neg(a2), r = s2, s = sat.neg(a1);
    			else         p = sat.neg(s1), q = sat.neg(a2), r = sat.neg(s2), s = sat.neg(a1);
    		} else {
    			if (a1 < a2) p = s1, q = a2, r = s2, s = a1;
    			else	     p = sat.neg(s1), q = a2, r = sat.neg(s2), s = a1;
    		}

    		// r or p and r or q and s or p and s or q
    		sat.implication(r, p);
    		sat.implication(r, q);
    		sat.implication(s, p);
    		sat.implication(s, q);
    	}

    	cout << (sat.possible() ? "Yes" : "No") << '\n';
    }
}
