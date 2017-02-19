#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 100010;

int cases;
int dp[MAX];
int cycle[MAX];

int go(int u, vector<int> &next, int time) {
    if(dp[u] != -1) return dp[u];
    if(cycle[next[u]] != -1) {
        int total = time - cycle[ next[u] ]+1;
        dp[u] = total;
        for(int i = next[u]; i != u; i = next[i]) {
            dp[i] = total;
        }
        return 0;
    }
    cycle[u] = time;
    int x = 1+go(next[u], next, time+1);
    cycle[u] = -1;
    if(dp[u] == -1) dp[u] = x;
    return dp[u];
}

int main () {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> next(n+1, -1);
        dp[0] = -1;
        cycle[0] = -1;
        for(int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            next[a] = b;
            dp[i] = -1;
            cycle[i] = -1;
        }

        int best_len = 0, best_node = n+2;
        for(int i = 1; i <= n; i++) {
            int len = go(i, next, 1);
            if(len > best_len) {
                best_node = i;
                best_len = len;
            }
        }

        cout << "Case " << ++cases << ": " << best_node << "\n";
    }

}
