#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iiii;

const int INF = INT_MAX/4;
const int MAX = 70001;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int cases;

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> square;
    for(ll i = 1; i*i <= 1000000000ll; i++) {
        square.push_back(i*i);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> ans;
        for(int i = 0;; i++) {
            ll x = n-square[i];
            if(x <= 0) break;
            if(x % (i+1) == 0 && x != 0) {
                ans.push_back(x);
            }
        }
        cout << "Case " << ++cases << ":";
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << "\n";
    }

}
