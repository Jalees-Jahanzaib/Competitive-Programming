#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100010
#define INF INT_MAX/2
#define ll long long
#define MOD 1000000007

#define BLUE 2
#define WHITE 0
#define RED 1

using namespace std;

ll dp[46][3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int n; cin >> n;
    dp[1][RED] = dp[1][WHITE] = 1ll;
    //cout << dp[1][RED] << " " << dp[1][WHITE] << " " << dp[1][BLUE] << endl;
    for(int i = 2; i <= n; i++) {
        dp[i][RED] = dp[i-1][WHITE] + dp[i-1][BLUE] - dp[i-2][RED];
        dp[i][WHITE] = dp[i-1][RED] + dp[i-1][BLUE] - dp[i-2][WHITE];
        dp[i][BLUE] = dp[i-1][RED] + dp[i-1][WHITE];
        //cout << dp[i][RED] << " " << dp[i][WHITE] << " " << dp[i][BLUE] << endl;
    }

    cout << dp[n][WHITE] + dp[n][RED] << "\n";



}
