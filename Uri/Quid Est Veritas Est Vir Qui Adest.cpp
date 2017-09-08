#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e5 + 10;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

ll fpow(ll a, ll b, ll MOD) {
    ll ans = 1LL;
    while(b > 0) {
        if(b&1) ans = (ans*a)%MOD;
        a =(a*a)%MOD;
        b >>= 1LL;
    }
    return ans;
}

ll fact[MAX], inv[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1]*i) % MOD;
        inv[i] = fpow(fact[i], MOD-2, MOD);
    }

    string line;
    while(cin >> line) {
        vector<int> frec(255);
        for(int i = 0; i < line.size(); i++) {
            frec[ line[i] ]++;
        }

        ll ans = fact[int(line.size())];
        for(int i = 0; i < 255; i++) {
            if(frec[i] == 0) continue;
            ans = (ans * inv[ frec[i] ]) % MOD;
        }

        cout << ans << "\n";


    }
}
