#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 1000;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string line; cin >> line;
        int n = line.size();
        vector<ll> dp(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(line[i] == '0') {
                dp[i+1] = max(dp[i+1], dp[i]);
            } else {
                ll num = 0;
                for(int j = i; j < n; j++)  {
                    num = num*10 + (line[j]-'0');
                    if(num > INT_MAX) break;
                    dp[j+1] = max(dp[j+1], dp[i]+num);
                }
//                cout << num << endl;
            }
        }

        cout << dp[n] << "\n";
    }
}
