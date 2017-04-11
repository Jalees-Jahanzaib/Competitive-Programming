#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 10;
const double EPS = 1e-5;
const int INF = INT_MAX;

char board[MAX][MAX];
int dp[MAX][MAX];

int val(char c) {
    if(c == 'A') return 1;
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return c-'0';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n; cin >> n;
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            string s; cin >> s;
            board[i][j] = s[0];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + val(board[i][j]);
        }
    }

    cout << dp[n][n] << "\n";


}
