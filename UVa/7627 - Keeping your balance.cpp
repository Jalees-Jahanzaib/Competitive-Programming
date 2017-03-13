#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    while(cin >> n && n != -1) {
        int m; cin >> m;
        ll ans = 1;
        for(ll i = n; i >= n-m; i--) {
            ans = ans/__gcd(ans, i)*i;
        }
        cout << ans << "\n";
    }

}

