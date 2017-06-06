#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 21;
const double EPS = 1e-5;
const int INF = INT_MAX;

double prob[MAX][MAX];
double dp[1<<20];
int n;

double go(int mask) {
    int mission = __builtin_popcount(mask);
    if(mission == n) return 100.0;
    double &r = dp[mask];
    if(r == -1.0) {
        r = 0.0;
        for(int i = 0; i < n; i++) {
            if((mask>>i)&1) continue;
            r = max(r, prob[i][mission]*go(mask|(1<<i)));
        }
        r /= 100.0;
//        cout << bitset<2>(mask) << " " << mission << " " << r << endl;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY


    cin >> n;
    for(int i = 0; i < 1<<n; i++) {
        dp[i] = -1.0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> prob[i][j];
        }
    }

    cout << fixed << setprecision(6) << go(0) << "\n";

}
