#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 500 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

vector< vector<int> > G;
int n, t;

int dfs(int u, vector<bool> &seen) {
    seen[u] = true;
    int ret = 1;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!seen[v]) {
            ret += dfs(v, seen);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/
    while(cin >> n && n != 0) {
        G = vector< vector<int> >(n + 2);
        vector<int> degree(n + 2, 0);

        for(int i = 0; i < n; i++) {
            cin >> t;
            int x;
            for(int j = 0; j < t; j++) {
                cin >> x;
                G[i + 1].PB(x);
                degree[x]++;
            }
        }
        int best = -1, idx = -1;
        for(int i = 1; i <= n; i++) {
            if(degree[i] == 0) {
                vector<bool> seen(n + 2, false);
                int r = dfs(i, seen);
                if(best < r) {
                    idx = i;
                    best = r;
                }
            }
        }

        cout << idx << "\n";

    }


}
