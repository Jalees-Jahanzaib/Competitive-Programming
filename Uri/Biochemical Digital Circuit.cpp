#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int MOD = 1000000007;
const int MAX = 1010;

int board[1000 + 10][1000 + 10], p, n, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> p >> n >> c && p != 0 && n != 0 && c != 0) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < p; j++)
                cin >> board[i][j];

        int ans = 0;
        for(int i = 0; i < p; i++) {
            int cont = 0;
            for(int j = 0; j < n; j++) {
                if(board[j][i] == 1) cont++;
                else {
                    if(cont >= c) ans++;
                    cont = 0;
                }
            }
            if(cont >= c) ans++;
        }

        cout << ans << endl;

    }
}
