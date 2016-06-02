#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(300 * 2 + 1) + 10
#define INF INT_MIN / 5;
#define ll long long
#define lt 8
#define up 2
#define down 1
#define rt 4

using namespace std;
/// LRUD
/// 1111
const int DX[] = {0,0,-1,1};
const int DY[] = {-1,1,0,0};
const int dir[] = {lt, rt, up, down};
int n, board[MAX][MAX];
bool seen[MAX][MAX];

void bfs(int x, int y) {
    queue<int> q;
    q.push(x);
    q.push(y);
    seen[x][y] = true;
    while(!q.empty()) {
        int x_ = q.front(); q.pop();
        int y_ = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x_ + DX[i];
            int ny = y_ + DY[i];

            if(nx >= 0 && ny >= 0 && nx < 2*n && ny < (2*n + 1) && !seen[nx][ny] && !(board[x_][y_] & dir[i])) {
                q.push(nx);
                q.push(ny);
                seen[nx][ny] = true;
            }
        }
    }
}

char c;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/
    //freopen("input.txt", "r", stdin);

    while(cin >> n) {
        memset(board, 0, sizeof(board));
        memset(seen, false, sizeof seen);

        int x, y;
        for(int i = 1; i <= 2*n - 1; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> c;
                if(i % 2) x = i, y = 2 * j - 1;
                else x = i, y = 2 * j;
                if(c == 'H') {
                    board[x - 1][y - 1] |= down;
                    board[x - 1][y] |= down;
                    board[x][y - 1] |= up;
                    board[x][y] |= up;
                }
                else {
                    board[x - 1][y - 1] |= rt;
                    board[x - 1][y] |= lt;
                    board[x][y - 1] |= rt;
                    board[x][y] |= lt;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 2*n; i++) {
            for(int j = 0; j < 2*n + 1; j++) {
                if(!seen[i][j]) bfs(i, j), ans++;
            }
        }

        cout << ans - 1 << "\n";
    }
}
