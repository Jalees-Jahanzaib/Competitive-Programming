#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 110;
const int INF = INT_MAX/3;
const int MAXLOG = 20;

int n;

int furthest(int s, vector<vector<int>> &g, vector<int> &prev) {
    queue<int> q;
    q.push(s); q.push(-1);
    prev[s] = -1;
    int u;
    while(q.size()) {
        u = q.front(); q.pop();
        int p = q.front(); q.pop();

        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(v != p) {
                q.push(v); q.push(u);
                prev[v] = u;
            }
        }
    }
    return u;
}

vector<int> get_center(vector<vector<int>> &g) {
    vector<int> prev(n+1);
    int u = furthest(1, g, prev);
    int v = furthest(u, g, prev);

    vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = prev[v];
    }

    vector<int> ret;
    ret.push_back(path[ path.size() / 2 ]);
    if(path.size() % 2 == 0) {
        ret.push_back(path[ path.size() / 2 - 1]);
    }

    return ret;
}

string get_tree(int u, int p, vector<vector<int>> &g) {
    string ret = "(";
    vector<string> child;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != p) {
            child.push_back(get_tree(v, u, g));
        }
    }
    sort(child.begin(), child.end());
    for(int i = 0; i < child.size(); i++) {
        ret += child[i];
    }
    ret.push_back(')');
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    while(cin >> n) {
        vector<vector<int>> g1(n+1), g2(n+1);
        vector<int> deg1(n+1), deg2(n+1);
        for(int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            g1[a].push_back(b);
            g1[b].push_back(a);
        }

        for(int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            g2[a].push_back(b);
            g2[b].push_back(a);
        }

        vector<int> cen1 = get_center(g1);
        vector<int> cen2 = get_center(g2);

        vector<string> tree1;
        for(int i = 0; i < cen1.size(); i++) {
            tree1.push_back( get_tree(cen1[i], -1, g1) );
        }
        vector<string> tree2;
        for(int i = 0; i < cen2.size(); i++) {
            tree2.push_back( get_tree(cen2[i], -1, g2) );
        }

        bool ok = false;
        for(int i = 0; i < tree1.size(); i++) {
            for(int j = 0; j < tree2.size(); j++) {
                if(tree1[i] == tree2[j])
                    ok = true;
            }
        }

        if(ok) cout << "S\n";
        else cout << "N\n";

    }
}
