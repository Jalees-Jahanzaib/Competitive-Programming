#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<lf, lf> dd;

const lf INF = 1e12;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, d, r;
    while(cin >> n >> d >> r && (n+d+r) != 0) {
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<ll> v2(n);
        for(int i = 0; i < n; i++) cin >> v2[i];
        sort(v2.rbegin(), v2.rend());
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] + v2[i] > d) {
                sum += r*(v[i]+v2[i]-d);
            }
        }

        cout << sum << "\n";
    }

}
