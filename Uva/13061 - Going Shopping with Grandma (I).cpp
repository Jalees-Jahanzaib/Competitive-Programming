#include <bits/stdc++.h>

#define PB push_back
#define iii pair<int, int>
#define MAX 3010
#define INF INT_MAX / 2
#define ll long long
#define MOD 9999959999ll

using namespace std;

ll dp[MAX][MAX];

ll go(int u, int v) {
    ll a = 0, b = 0;
    if(u > 0) {
        if(dp[u - 1][v + 1] == -1) go(u - 1, v + 1);
        a = dp[u - 1][v + 1];
    }
    if(v > 0) {
        if(dp[u][v - 1] == -1) go(u, v - 1);
        b = dp[u][v - 1];
    }

    return dp[u][v] = (a + b + 1ll) % MOD;
}

int T, l, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof dp);
    while(cin >> l >> s && (l + s != 0))
        cout << (dp[l][s] == -1 ? go(l, s) : dp[l][s]) << "\n";



}
