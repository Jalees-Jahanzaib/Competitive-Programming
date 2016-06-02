#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin)
    int n, m, u, d, x;
    while(cin >> n >> m) {
        int best = INT_MAX;
        for(int i = 0; i < m; i++) {
            cin >> u >> d;
            x = (n*d)*1.0 / (u+d)*1.0 + 1;
            best = min(best, u*x - (n-x)*d);
        }
        cout << best << "\n";
    }
}
