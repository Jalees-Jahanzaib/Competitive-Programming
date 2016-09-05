#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 1010
#define INF INT_MAX
#define ll long long
#define MOD 1000000007

#define root double(sqrt(20000))

using namespace std;

bool can[MAX][MAX];
double dp[MAX][MAX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int n, m, q, a, b;
    cin >> m >> n;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> b >> a;
        b--; a--;
        can[a][b] = true;
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++)
            dp[i][j] = INF*1.0;
    }

    dp[0][0] = 0.0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i+1][j] = fmin(dp[i+1][j], dp[i][j] + 100.0);
            dp[i][j+1] = fmin(dp[i][j+1], dp[i][j] + 100.0);
            if(can[i][j]) {
                dp[i+1][j+1] = fmin(dp[i+1][j+1], dp[i][j] + root);
            }
        }
    }

    cout << int(round(dp[n][m])) << "\n";



}
