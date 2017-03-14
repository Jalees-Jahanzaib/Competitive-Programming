#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 200;
const double EPS = 1e-5;
const int INF = INT_MAX/2;
const ll MOD = 1000000007;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

ll fpow(ll a, ll b, ll MOD) {
    ll ans = 1LL;
    while(b > 0) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1LL;
    }
    return ans;
}


int main() {
     ios_base::sync_with_stdio(0);
//     cin.tie(0);

    ll a, b; cin >> a >> b;
    cout << fpow(a, b, MOD) << "\n";

}
