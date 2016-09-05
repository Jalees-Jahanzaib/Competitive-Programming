#include <bits/stdc++.h>

#define PB push_back
#define ii pair< int, int >
#define state pair< int, ii >
#define MAX 100010
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

typedef long double lf;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n, m;
    while(cin >> n >> m) {
        vector<int> v(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x; cin >> x;
                if(x > 0) v[i]++;
            }
            if(v[i] == m) ans++;
        }
        cout << ans << "\n";
    }



}

