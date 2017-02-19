#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

string a, b;
int nexta[MAXN][26], nextb[MAXN][26], total[26];
int n, m;
int dp[MAXN][MAXN];

int go(int i, int j) {
    if(i == n && j == m) return 0;
    int &r = dp[i][j];
    if(r == -1) {
        r = INT_MAX;
        int pos = (i+j)+2;
        if(i < n) {
            int lettera = a[i]-'A';
            if(nexta[i][lettera]+nextb[j][lettera] == total[lettera]) {
                if(total[lettera] != 1)
                    r = min(r, go(i+1, j)-pos);
                else
                    r = min(r, go(i+1, j));
            } else if(nexta[i][lettera]+nextb[j][lettera] == 1) {
                r = min(r, go(i+1, j)+pos);
            } else {
                r = min(r, go(i+1, j));
            }
        }
        if(j < m) {
            int letterb = b[j]-'A';
            if(nexta[i][letterb]+nextb[j][letterb] == total[letterb]) {
                if(total[letterb] != 1)
                    r = min(r, go(i, j+1)-pos);
                else
                     r = min(r, go(i, j+1));
            } else if(nexta[i][letterb]+nextb[j][letterb] == 1) {
                r = min(r, go(i, j+1)+pos);
            } else {
                r = min(r, go(i, j+1));
            }
        }
    }
    return r;
}

int main () {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> a >> b;
        n = a.size(); m = b.size();
        for(int i = 0; i < 26; i++) {
            nexta[n][i] = 0;
            nextb[m][i] = 0;
            total[i] = 0;
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < 26; j++) {
                nexta[i][j] = nexta[i+1][j]+(j == a[i]-'A');
            }
            total[ a[i]-'A' ]++;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = 0; j < 26; j++) {
                nextb[i][j] = nextb[i+1][j]+(j == b[i]-'A');
            }
            total[ b[i]-'A' ]++;
        }

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                dp[i][j] = -1;

        cout << go(0, 0) << "\n";
    }

}
