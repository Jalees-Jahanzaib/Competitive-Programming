#include <bits/stdc++.h>

#define PB push_back
#define iii pair<int, int>
#define MAX 1010
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007L

using namespace std;

string board[MAX];
int L, start, finish, m, v;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    board[0] = string(1008, '.');
    while(cin >> L && L != 0) {
        cin >> start >> finish >> m >> v;
        L++;
        for(int i = 1; i <= m; i++) cin >> board[i];

        vector< vector<int> > dp(m + 2, vector<int>(L + 2, INF));
        dp[0][start] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < L; j++) {
                if(dp[i][j] != INF) {
                    for(int k = 0; k <= v; k++) {
                        if(j + k >= L || board[i + 1][j + k] == 'X') break;
                        dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + k);
                    }
                    for(int k = 0; k <= v; k++) {
                        if(j - k < 0 || board[i + 1][j - k] == 'X') break;
                        dp[i + 1][j - k] = min(dp[i + 1][j - k], dp[i][j] + k);
                    }
                }
            }
        }

        if(dp[m][finish] == INF) cout << "-1\n";
        else cout << dp[m][finish] << "\n";

    }




}

