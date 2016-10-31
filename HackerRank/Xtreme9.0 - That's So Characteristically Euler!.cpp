#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = INT_MAX;
const int MAX = 1010;

const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

char board[MAX][MAX];
bool seen[MAX][MAX];

int n, m;

void fill_up(int a, int b, char c) {
    queue<int> q;
    q.push(a); q.push(b);
    seen[a][b] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();

        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                if(c == 'O' && abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && ny >= 0 && nx <= n+1 && ny <= m+1 && board[nx][ny] == c && !seen[nx][ny]) {
                    seen[nx][ny] = true;
                    q.push(nx);
                    q.push(ny);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        memset(board, 'O', sizeof board);
        memset(seen, false, sizeof seen);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> board[i][j];
            }
        }

        fill_up(0, 0, 'O');

        int holes = 0, zones = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(!seen[i][j] && board[i][j] == 'O') {
                    fill_up(i, j, 'O');
                    holes++;
                }
                if(!seen[i][j] && board[i][j] == 'X') {
                    fill_up(i, j, 'X');
                    zones++;
                }
            }
        }

        cout << zones - holes << "\n";
    }

}
