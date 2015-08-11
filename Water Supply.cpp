#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e3 + 10)
#define INF INT_MIN / 5;

using namespace std;

int n, m, dp[MAX];
vector<vector<int> > G;
bool seen[MAX];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    seen[x] = true;
    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(int i = 0; i < G[node].size(); i++) {
            int next = G[node][i];
            if(!seen[next]) {
                seen[next] = true;
                q.push(next);
            }
        }
    }
}

priority_queue<ii> pq;
int dfs(int node) {
    int sum = 1;
    for(int i = 0; i < G[node].size(); i++) {
        int next = G[node][i];
        if(!seen[next]) {
            if(dp[next] != -1) sum += dp[next];
            else {
                seen[next] = true;
                sum += dfs(next);
                seen[next] = false;
            }
        }
    }

    return dp[node] = sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n >> m) {
        memset(seen, false, sizeof(seen));
        memset(dp, -1, sizeof(dp));
        G = vector<vector<int> >(n + 1);

        int from, to;
        for(int i = 0; i < m; i++) {
            cin >> from >> to;
            G[from].PB(to);
        }

        bfs(0);

        for(int i = 0; i <= n; i++)
            if(!seen[i] && dp[i] == -1) {
                seen[i] = true;
                pq.push(ii(dfs(i), i));
                seen[i] = false;
            }

        int ans = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int cant = pq.top().first;
            pq.pop();

            if(seen[node]) continue;

            bfs(node);
            ans++;
        }

        cout << ans << "\n";
    }


}
