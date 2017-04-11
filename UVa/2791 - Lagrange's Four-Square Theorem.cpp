#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 32780;
const double EPS = 1e-5;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n;
    while(cin >> n && n) {
        int ans = 0;
        int lim = sqrt(n)+1;
        for(int i = 0; i < lim; i++) {
            if(i*i > n) break;
            for(int j = i; j < lim; j++) {
                if(i*i + j*j > n) break;
                for(int k = j; k < lim; k++) {
                    int sum = i*i + j*j + k*k;
                    int res = n - sum;
                    if(res < 0) break;

                    int x = sqrt(res);
                    if(x < k) continue;

                    if(x*x == res) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }




}
