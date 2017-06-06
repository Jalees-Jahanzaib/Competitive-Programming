#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 1005;
const int INF = INT_MAX/3;
const int MAXLOG = 20;

int f[MAX];

int find(int x) {
    return f[x] = x == f[x] ? x : find(f[x]);
}

int merge(int a, int b) {
    f[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) f[i] = i;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            merge(i, x);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += find(i) == i;
        }
        cout << ans << "\n";
    }

}
