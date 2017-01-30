#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("snowmen.in", "r", stdin);
    freopen("snowmen.out", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<int> taken_from(n+1, -1);
    vector<ll> top(n+1, 0);
    vector<ll> mass(n+1, 0);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int from; ll x;
        scanf("%d %lld", &from, &x);
        if(x == 0) {
            mass[i] = mass[from] - top[from];
            top[i] = top[ taken_from[from] ];
            taken_from[i] = taken_from[ taken_from[from] ];
        } else {
            mass[i] = mass[from] + x;
            top[i] = x;
            taken_from[i] = from;
        }
        ans += mass[i];
    }
    printf("%lld\n", ans);

    return 0;

}
