#include<bits/stdc++.h>

#define ll long long
#define dd pair<double, double>
#define ii pair<int, int>
#define PB push_back
#define checkk x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX int(1e3 + 10)
#define INF LONG_LONG_MAX / 6;
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2
#define PI acos(-1)

using namespace std;

int c, label[MAX], n, m;
bool seen[MAX], cycle[MAX], ok, flag, used[MAX][MAX];
set<int> components;
vector< vector<int> > G, RG;

void counting(int node) {
    seen[node] = true;

    for(int i = 0; i < RG[node].size(); i++)
        if(!seen[RG[node][i]])
            counting(RG[node][i]);
}

void solve(int node) {
    seen[node] = true;

    bool childrens = false;
    for(int i = 0; i < G[node].size(); i++) {
        childrens = true;
        if(cycle[G[node][i]]) ok = false/*, cout << "entre con -> " << G[node][i] << endl */;
        if(!seen[G[node][i]]) {
            cycle[G[node][i]] = true;
            solve(G[node][i]);
            cycle[G[node][i]] = false;
        }
    }

    if(!childrens) components.insert(node);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/

    while(cin >> n >> m && (n != 0 || m != 0)) {
        memset(seen, false, sizeof seen);
        memset(used, false, sizeof(used));
        G = vector< vector<int> >(n);
        RG = vector< vector<int> >(n);

        ok = true;

        int from, to;
        for(int i = 0; i < m; i++) {
            cin >> from >> to;
            if(used[from][to]) continue;
            used[from][to] = true;
            G[from].PB(to);
            RG[from].PB(to);
            RG[to].PB(from);
            if(from == to) ok = false;
        }

        c = 0;
        for(int i = 0; i < n; i++) {
            if(!seen[i]) {
                counting(i);
                c++;
            }
        }

        components.clear();
        memset(seen, false, sizeof seen);
        for(int i = 0; i < n && ok; i++)
            if(!seen[i])
                solve(i);

        ok &= components.size() == c;

        if(ok) cout << "1\n";
        else cout << "0\n";

    }
}
