#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF -1.0
#define ll long long
#define MOD 1000000007L

using namespace std;

int t, p;

int main() {
    cin >> t;

    while(t--) {
        cin >> p;
        vector<int> v(p + 1);
        for(int i = 0; i <= p; i++) cin >> v[i];

        double k, d;
        cin >> d >> k;
        k = k/d;

        double n = 1.0 + sqrt(1.0 + 8.0*k);
        n /= 2.0;

        unsigned long long x = (unsigned long long)(ceil(n) - 1ll);
        unsigned long long ans = 0, pot = 1ll;
        for(int i = 0; i <= p; i++) {
            ans += v[i] * pot;
            pot *= x;
        }

        cout << ans << "\n";

    }

}


