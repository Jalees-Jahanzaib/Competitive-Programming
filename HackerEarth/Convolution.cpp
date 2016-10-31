#include<bits/stdc++.h>

using namespace std;

const int MAX = 1010;

typedef long long ll;

ll acc[MAX][MAX];

int main() {
    int n, m, p, q; cin >> n >> m >> p >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> acc[i][j];
            acc[i][j] += acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
            if ( i >= p && j >= q )
                cout << acc[i][j] + acc[i-p][j-q] - acc[i][j-q] - acc[i-p][j]
                    << " \n"[j==m];
        }
    }

    return 0;
}
