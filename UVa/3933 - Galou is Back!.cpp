#include<bits/stdc++.h>

using namespace std;

const int DX[] = {0 ,  0  , 1 , -1 , -1 ,  1};
const int DY[] = {1 , -1  , 0 ,  0 , 1 , -1};

int R, C;
string board[200];
int color[200][200];
bool seen[200][200];

void dfs(int x, int y, int c) {
    color[x][y] = c;
    board[x][y] = (color[x][y] == 0 ? '(' : ')');

    for(int i = 0; i < 6; i++) {
        int nx = x + DX[i];
        int ny = y + DY[i];
        if(nx >= 0 && ny >= 0 && nx < R && ny < C && board[nx][ny] != 'I' && board[nx][ny] != '.') {
            if(color[nx][ny] == -1) dfs(nx, ny, 1 - c);
            else if(color[nx][ny] != 1 - c) {
                board[x][y] = 'B';
                color[x][y] = 2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> R >> C && (R + C != 0)) {
        memset(color, -1, sizeof color);
        memset(seen, false, sizeof seen);
        for(int i = 0; i < R; i++) cin >> board[i];

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(board[i][j] == 'I')
                    dfs(i, j, 0);

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(board[i][j] == 'B' && !seen[i][j]) {
                    queue<int> q;
                    q.push(i); q.push(j);
                    seen[i][j] = true;
                    while(!q.empty()) {
                        int x = q.front(); q.pop();
                        int y = q.front(); q.pop();

                        board[x][y] = 'B';

                        for(int i = 0; i < 6; i++) {
                            int nx = x + DX[i];
                            int ny = y + DY[i];
                            if(nx >= 0 && ny >= 0 && nx < R && ny < C && !seen[nx][ny] && board[nx][ny] != '.') {
                                q.push(nx); q.push(ny);
                                seen[nx][ny] = true;
                            }
                        }
                    }
                }

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(board[i][j] == '*')
                    board[i][j] = 'F';


        cout << "\n";
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                cout << board[i][j];
            cout << "\n";
        }
    }

}
