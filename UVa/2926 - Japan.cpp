#include<bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define PB push_back
#define MAX 1010
#define MAXLOG 15
#define INF 1LL<<60
#define MOD (987654321LL)
#define gauss(n) (n) * ((n)+1ll) / 2ll
#define PI acos(-1)
#define EPS (long double)(1e-12);

using namespace std;

int bit[MAX];

void update(int x, int val) {
    for(; x < MAX; x += x&-x)
        bit[x] += val;
}

int get(int x) {
    int ans = 0;
    for(; x > 0; x -= x&-x)
        ans += bit[x];
    return ans;
}


int main() {
    int t; cin >> t;

    for(int c = 1; c <= t; c++) {
        memset(bit, 0, sizeof bit);
        int n, m, k;
        cin >> n >> m >> k;
        vector<ii> v(k);
        for(int i = 0; i < k; i++) cin >> v[i].first >> v[i].second;

        sort(v.begin(), v.end());

        ll ans = 0;
        for(int i = 0; i < k; i++) {
            ans += (ll)(get(v[i].second+1));
            update(1, 1);
            update(v[i].second+1, -1);
        }

        cout << "Test case " << c << ": " << ans << "\n";
    }
}
