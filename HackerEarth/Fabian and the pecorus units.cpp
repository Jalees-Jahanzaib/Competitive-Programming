#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAX = 1010;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int cur = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cur += x;
            ans = min(ans, cur);
        }

        cout << abs(ans) << "\n";
    }
}
