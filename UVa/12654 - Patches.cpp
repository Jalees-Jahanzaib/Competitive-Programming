#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 1005;
int dist[2 * MAX], dp[2 * MAX];

int a, b, len;

int limit;
int go (int n) {
    if (n <= limit) return 0;
    int &r = dp[n];
    if (r == -1) {
        int fa = lower_bound(dist, dist + len, dist[n] - a) - dist - 1;
        int fb = lower_bound(dist, dist + len, dist[n] - b) - dist - 1;


        r = min(go(fa) + a, go(fb) + b);

//        cout << n << ' ' << fa << ' ' << fb << endl;
//        cout << r << endl;
    }
    return r;
}


int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

     int n, c;
     while (cin >> n >> c >> a >> b) {
        for (int i = 0; i < n; ++i) {
            cin >> dist[i];
            dist[n + i] = c + dist[i];
        }

        int ans = INT_MAX;
        len = 2 * n;
        for (int i = n; i < 2 * n; ++i) {
            limit = i - n + 1;
            memset(dp, -1, sizeof dp);
            ans = min(ans, go(i));

//            cout << limit << ' ' << ans << endl;
        }

        cout << ans << '\n';
     }
}
