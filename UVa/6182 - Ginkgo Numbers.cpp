#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 3162280;
const double EPS = 1e-5;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        int p, q; cin >> p >> q;
        int ans = 0;
        int lim = sqrt(p*p + q*q)+1;
        for(int m = -lim; m <= lim; m++) {
            for(int n = -lim; n <= lim; n++) {
                int a = m*p+n*q, b = m*q-n*p;
                int s = m*m + n*n;
                if(s > 0){
                    if(a % s == 0 && b % s == 0) {
                        ans++;
                    }
                }
            }
        }
        if(ans == 8 && p*p + q*q > 1) cout << "P\n";
        else cout << "C\n";
    }
}
