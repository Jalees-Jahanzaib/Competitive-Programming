#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, bool> ii;

const int MAX = 202;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    ll n, l, u;
    while(cin >> n >> l >> u) {
        ll ans = 0;
        for(ll i = 33; i >= 0; i--) {
            if( (n>>i)&1 ) { /// 1
                ll nxt = ans + (1ll << i) - 1;
                if(!(nxt >= l))
                    ans += (1ll << i);
            } else { /// 0
                ll nxt = ans + (1ll << i);
                if(nxt <= u) {
                    ans += (1ll << i);
                }
            }
        }

        cout << ans << endl;
    }
}
