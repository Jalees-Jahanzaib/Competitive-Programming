#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e4 + 10)
#define INF INT_MAX / 4
#define ll long long
#define LEFT 1
#define RIGHT 2
#define gauss(x) (x)*(x+1)/2

using namespace std;

int n, t, b, dp[200];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n && n != 0) {

        int sum = 0;
        vector<ii> trip;
        for(int i = 0; i < n; i++) {
            cin >> t >> b;
            trip.PB(ii(t, i));
            dp[i] = sum;
            sum += b;
        }

        sort(trip.rbegin(), trip.rend());

        int used = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            //cout <<trip[i].first << " " << trip[i].second << " " << dp[trip[i].second] << endl;
            if(dp[trip[i].second] > 0) {
                ans += trip[i].first / 2;
                for(int j = trip[i].second - 1; j >= 0 && dp[j] == dp[trip[i].second]; j--)
                    dp[j]--;
                for(int j = trip[i].second; j < n; j++)
                    dp[j]--;
            }
            else
                ans += trip[i].first;
        }

        cout << ans << "\n";
    }


}
