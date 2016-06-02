#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 10000 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;


vector< vector<int> > G;
int n, dp[MAX][12];

void go(int u, int p) {

    for(int k = 0; k < G[u].size(); k++) {
        int v = G[u][k];
        if(v == p) continue;
        go(v, u);
        for(int i = 1; i <= 6; i++) {
            int best = INF;
            for(int j = 1; j <= 6; j++) {
                if(i == j) continue;
                best = min(best, dp[v][j]);
            }
            dp[u][i] += best;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);

    while(cin >> n && n != 0) {
        G = vector< vector<int> >(n + 2);
        int u, v;
        char c;
        string line;
        for(int i = 0; i < n; i++) {
            cin >> u >> c;
            getline(cin, line);
            stringstream ss(line);
            while(ss >> v) G[u].PB(v), G[v].PB(u);
        }

        for(int i = 0; i < n; i++)
            for(int j = 1; j <= 6; j++)
                dp[i][j] = j;

        go(0, -1);
        int ans = INF;
        for(int i = 1; i <= 6; i++) {
            ans = min(ans, dp[0][i]);
        }

        cout << ans << "\n";

    }

}
