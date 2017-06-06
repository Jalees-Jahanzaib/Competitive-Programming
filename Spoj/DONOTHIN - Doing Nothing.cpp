#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 1005;
const int INF = INT_MAX/3;
const int MAXLOG = 20;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n, m;
    while(cin >> n >> m && n != -1) {
        ll ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            ans += sum + x;
            sum += x;
        }
        cout << ans*m << "\n";
    }
}
