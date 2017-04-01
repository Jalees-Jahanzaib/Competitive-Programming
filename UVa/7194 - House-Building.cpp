#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 60;
const double EPS = 1e-5;
const int INF = INT_MAX;
const ll MOD = int(1e9) + 7;

const int DX[] = {1, -1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int board[MAX][MAX];

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        memset(board, 0, sizeof board);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> board[i][j];
                ans += (board[i][j] > 0);
            }
        }
//        cout << " -> " << ans << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                ans += max(0, board[i][j]-board[i][j-1]);
            }
            for(int j = m; j >= 1; j--) {
                ans += max(0, board[i][j]-board[i][j+1]);
            }
//            cout << ans << endl;
        }



        for(int j = 1; j <= m; j++) {
            for(int i = 1; i <= n; i++) {
                ans += max(0, board[i][j]-board[i-1][j]);
            }
            for(int i = n; i >= 1; i--) {
                ans += max(0, board[i][j]-board[i+1][j]);
            }
        }

        cout << ans << "\n";

    }

}
