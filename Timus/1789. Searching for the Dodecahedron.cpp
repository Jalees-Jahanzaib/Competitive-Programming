#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 1010;
const double EPS = 1e-5;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    int n; cin >> n;
    cout << 2*n << "\n";
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    for(int i = n; i >= 2; i--) {
        cout << i << " ";
    }
    cout << 1 << "\n";




}
