#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 50010;
const double EPS = 1e-5;
const int INF = INT_MAX/4;

map<ll, int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    int ans = 0;
    for(int i = 0; i < n1+n2+n3; i++) {
        ll x; cin >> x;
        cnt[x]++;
        ans += cnt[x] == 2;
    }
    cout << ans << "\n";
    for(map<ll, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        if(it->second >= 2) cout << it->first << "\n";
    }

}
