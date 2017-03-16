#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 55;
const double EPS = 1e-5;
const int INF = INT_MAX/2;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

string s;
int n;

int dp[MAX][MAX][27];

int go(int l, int r, int let) {
    if(l == r) {
        return let+'A' != s[l];
    }

    int &ret = dp[l][r][let];

    if(ret == -1) {
        ret = INF;
        for(int i = l; i <= r-1; i++) {
            for(int c = 0; c < 26; c++) {
                ret = min(ret, (c != let) + go(l, i, c) + go(i+1, r, let));
            }
        }
    }

    return ret;

}

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // LOCAL

    while(cin >> n && n) {
        cin >> s;
        memset(dp, -1, sizeof dp);
        int ans = INF;
        for(int i = 0; i < 26; i++) {
            ans = min(ans, 1 + go(0, n-1, i));
        }

        cout << ans << "\n";
    }
}
