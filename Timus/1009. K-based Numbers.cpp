#include <bits/stdc++.h>

#define PB push_back
#define ii pair< int, int >
#define MAX 200
#define INF INT_MAX/2
#define ll long long
#define MOD 1000000007

using namespace std;

ll dp[1800][2];
int k;

ll go(int n, bool zero) {
    ll &r = dp[n][zero];
    if(dp[n][zero] != -1) return r;
    if(n == 0) return r = 1;
    r = 0;
    for(int i = (zero ? 0 : 1); i < k; i++)
        if(i == 0) r += go(n-1, false);
        else r += go(n-1, true);
    return r;
}

int main() {
    //freopen("algoritm.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    int n; cin >> n >> k;
    cout << go(n, false) << "\n";


}
