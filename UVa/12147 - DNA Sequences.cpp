    #include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 1010
#define INF 0x3fffffff
#define ll long long
#define MOD 1000000007

using namespace std;

int dp[MAX][MAX];
int k, n, m;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    while(cin >> k && k != 0) {
        memset(dp, 0, sizeof(dp));
        string a; cin >> a; n = a.size(); a = "."+a;
        string b; cin >> b; m = b.size(); b = "."+b;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int ok = 0;
                for(; i-ok > 0 && j-ok > 0 && a[i-ok] == b[j-ok];) {
                    ok++;
                    if(ok >= k) dp[i][j] = max(dp[i][j], dp[i-ok][j-ok] + ok);
                }
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }

        cout << dp[n][m] << "\n";
    }
}
