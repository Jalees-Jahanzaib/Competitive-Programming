#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 60006;
const double EPS = 1e-5;
const int INF = INT_MAX;

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

int get_number(string &s) {
    string t = s.substr(0, int(s.size())-1);
    istringstream ss(t);
    int ret;
    ss >> ret;
    return ret;
}

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

    int n, m;
    while(cin >> n >> m && (n+m != 0)) {
        /// 0-n-1 groom
        /// n-2*n-1 bride
        sat2 sat(2*n);
        sat.implication(n, n);
        for(int i = 0; i < n; i++) {
            sat.diff(i, i+n);
        }
        for(int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            int ida = get_number(a), idb = get_number(b);
            if(a.back() == 'w') ida += n;
            if(b.back() == 'w') idb += n;
///            n || h & w || n & w || h
            sat.implication(n, ida);
            sat.implication(n, idb);
            sat.implication(ida, idb);

        }

        if(sat.possible()) {
            bool val = sat.ans[n];
            for(int i = 1; i < n; i++) {
                if(i != 1) cout << " ";
                if(sat.ans[i] == val) cout << i << "h";
                else cout << i << "w";
            }
            cout << "\n";
        } else {
            cout << "bad luck\n";
        }
    }

}
