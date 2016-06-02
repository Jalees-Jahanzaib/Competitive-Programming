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

ll MOD, M, k, coef[20];

inline ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

ll powMod(ll base, ll exp) {
    ll ans = 1;
    while(exp > 0) {
        if(exp & 1) ans = mult(ans, base);
        base = mult(base, base);
        exp >>= 1;
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> MOD >> M && (MOD + M != 0)) {
        MOD++;
        cin >> k;
        for(int i = 0; i <= k; i++) cin >> coef[k - i];

        set<ll> s;
        do{
            ll ans = 0, grad = k;
            for(int i = 0; i <= k; i++, grad--)
                ans += mult(coef[i], powMod(M, grad));
            s.insert(ans % MOD);

            M--;
        }while(M >= 0);

        cout << s.size() << "\n";
    }

}
