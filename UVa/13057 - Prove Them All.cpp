#include <bits/stdc++.h>

#define PB push_back
#define iii pair<int, int>
#define MAX 100010
#define INF INT_MAX / 2
#define ll long long
#define MOD 1000000007L

using namespace std;

int T, n, m, id, cases, a, b;
vector< vector<int> > G;
int seen[MAX];
stack<int> s;

void dfs(int u, bool flag) {
    seen[u] = id;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(seen[v] != id)
            dfs(v, flag);
    }

    if(flag) s.push(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        G = vector< vector<int> >(n + 1);
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            a--; b--;
            G[a].PB(b);
        }

        id++;
        for(int i = 0; i < n; i++)
            if(seen[i] != id)
                dfs(i, true);

        id++;
        int ans = 0;
        while(!s.empty()) {
            int u = s.top(); s.pop();

            if(seen[u] != id) {
                dfs(u, false);
                ans++;
            }
        }

        cout << "Case " << ++cases << ": " << ans << "\n";
    }

}
