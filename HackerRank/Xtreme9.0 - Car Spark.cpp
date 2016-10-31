#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX/2;
const int MAX = 256;
const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<ii>> all(50);
        for(int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            all[a].push_back(ii(b, c));
        }

        vector<int> dp(50, -1);
        dp[0] = 0;
        for(int i = 0; i < 48; i++) {
            dp[i+1] = max(dp[i+1], dp[i]);
            for(int j = 0; j < all[i].size(); j++) {
                int next = all[i][j].first, cost = all[i][j].second;
                dp[ next ] = max(dp[next], dp[i] + cost);
            }
        }

        cout << dp[48] << "\n";
    }

}

