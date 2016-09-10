#include<bits/stdc++.h>
#define num first
#define den second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ii dp[10][1010];

bool cmp(ii a, ii b) {
    return (double)(a.num)*(double)(b.den) >= (double)(b.num)*(double)(a.den);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, budget;
    while(cin >> n >> budget) {
        vector<int> devices(n);
        for(int i = 0; i < n; i++) {
            cin >> devices[i];
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= budget; j++)
                dp[i][j] = ii(0, 1);

        ll a, b; int c;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < devices[i]; j++) {
                cin >> a >> b >> c;
                ii cur = ii(b-a, b);
                for(int k = 0; k <= budget; k++) {
                    if(i == 0) {
                        if(k-c >= 0) {
                            dp[i][k] = cmp(cur, dp[i][k]) ? cur : dp[i][k];
                        }
                    }
                    else if(k-c >= 0) {
                        ii tmp = ii(cur.num*dp[i-1][k-c].num, cur.den*dp[i-1][k-c].den);
                        dp[i][k] = cmp(tmp, dp[i][k]) ? tmp : dp[i][k];
                    }
                }
            }
        }

        ii ans = dp[n-1][budget];
        if(ans.num == ans.den) cout << "0/1\n";
        else {
            ans.num = ans.den - ans.num;
            ll gcd = __gcd(ans.num, ans.den);
            ans.num /= gcd; ans.den /= gcd;
            cout << ans.num << "/" << ans.den << "\n";
        }
    }
}
