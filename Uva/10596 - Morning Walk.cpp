#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 500 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

vector< vector<int> > G, RG;
stack<int> s;
vector<bool> seen;
int children;

int dfs1(int u) {
    children++;
    seen[u] = true;
    int ret = 0;
    for(int v : G[u]) {
        ret++;
        if(!seen[v])
            ret += dfs1(v);
    }
    return ret;
}

int n, m, a, b, c;
int main() {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);
    cout.tie(0);/**/
    while(cin >> n >> m) {
        G = vector< vector<int> >(n + 2);
        vector<int> degree(n + 2, 0);
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            G[a].PB(b);
            G[b].PB(a);
            degree[a]++;
            degree[b]++;
        }
        seen = vector<bool> (n + 2, false);
        int root = 0;
        for(int i = 0; i < n; i++)
            if(!seen[i]) {
                children = 0;
                dfs1(i);
                if(children > 1)
                    root++;
            }

        if(root == 1) {
            bool even = true;
            for(int i = 0; i < n; i++)
                even &= degree[i] % 2 == 0;
            if(even) {
                cout << "Possible\n";
            }
            else cout << "Not Possible\n";
        }
        else cout << "Not Possible\n";

    }


}
