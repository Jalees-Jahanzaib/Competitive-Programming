#include<bits/stdc++.h>

using namespace std;

typedef double lf;
typedef complex<lf> pt;

const int MAX = 300;
pt points[MAX];
int n, k;

lf dp[MAX][MAX];

lf go ( int m, int h ) {
    if ( h > m + 1 ) return INT_MAX;
    if ( m == 0 && h == 1 ) return 0;
    if ( h == 0 ) return INT_MAX;
    lf &r = dp[m][h];
    if ( r == -1.0 ) {
        r = INT_MAX;
        for ( int i = m - 1; i >= 0; --i ) {
            r = min(r, go(i, h - 1) + abs(points[m] - points[i]));
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.setf(ios_base::fixed);
    cout.precision(3);

    while ( cin >> n >> k ) {
        lf x, y;

        for ( int i = 0; i < n; ++i ) {
            cin >> x >> y;
            points[i] = pt(x, y);
        }

        for ( int i = 0; i <= n; ++i )
            for ( int j = 0; j <= n; ++j )
                dp[i][j] = -1.0;

        cout << go(n - 1, n - k) << '\n';
    }
}
