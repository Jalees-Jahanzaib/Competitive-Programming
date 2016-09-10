/// 0.0 seconds
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
const ll INF = LLONG_MAX/2ll;

int n;
map<ii, ll> dp;
vector<ll> amount;
ll hire, fire, salary;

ll go(int month, ll workers) {
    if(dp.count(ii(month, workers))) return dp[ii(month, workers)];
    ll &r = dp[ii(month, workers)];
    if(month == n-1) {return r = workers*salary; }
    r = INF;
    for(int i = month; i < amount.size(); i++) {
        if(amount[i] >= amount[month + 1]) {
            if(amount[i] >= workers) {
                r = min(r, (amount[i] - workers)*hire + go(month + 1, amount[i]));
            }
            else {
                r = min(r, (workers - amount[i])*fire + go(month + 1, amount[i]));
            }
        }
    }

    return r = r + workers*salary;

}

int cases;

int main() {
    while(cin >> n && n) {
        dp.clear();
        amount.resize(n);

        cin >> hire >> salary >> fire;
        for(int i = 0; i < n; i++) {
            cin >> amount[i];
        }

        cout << "Case " << ++cases << ", cost = $" << hire*amount[0] + go(0, amount[0]) << "\n";
    }
}
