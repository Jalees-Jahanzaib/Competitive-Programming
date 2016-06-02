#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 120
#define INF INT_MAX / 4
#define ll long long
#define LEFT 1
#define RIGHT 2
#define gauss(x) (x)*(x+1)/2

using namespace std;

ll fastPow(ll x, ll n) {
    ll ans = 1ll;
    while(n) {
        if(n % 2 == 1) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}

ll solve(ll x, ll pot) {
    ll pot10 = fastPow(10ll, pot);
    if(pot10 > x) return 0ll;
    ll aux = (x / pot10) % 10ll;
    return solve(x , pot + 1ll) + (aux)*(aux - 1ll)*pot10/2ll + aux*((x%pot10) + 1) + 45ll*aux*pot10/10ll*pot;

}
ll to1, to2;

int main () {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> to1 >> to2 && (to1 != 0 || to2 != 0)) {
        cout << solve(to2, 0) - solve(to1 - 1, 0) << "\n";
    }

}
