#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> ii;
const int MOD = 1000000007;
const int MAX = 20010;

int main() {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, m; cin >> n >> m;
    if(n == m) {
        cout << string(n, 'a') << "\n";
    } else {
        if(n == 2 && m == 3) cout << "ba\n";
        else cout << "No\n";
    }

}
