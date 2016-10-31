    #include<bits/stdc++.h>

#define MOD			1000000021LL
#define MAX_N		100000

using namespace std;

typedef long long ll;
const int INF = INT_MAX/2;

int main() {
    int n, m;
    int t; cin >> t;

    while(t--) {
        cin >> n >> m;
        vector<int> money(n);
        for(int i = 0; i < n; ++i) {
            cin >> money[i];
        }
        vector<int> dp(m+1, INF);
        dp[0] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if( i+money[j] <= m)
                    dp[ i+money[j] ] = min(dp[ i+money[j] ], dp[i] + 1);
            }
//            cout << i << " " << dp[i] << endl;
        }

        cout << dp[m] << "\n";
    }




}
