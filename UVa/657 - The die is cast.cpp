#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ll long long
#define ii pair<int, char>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 50 + 10
#define INF 0xffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

char board[MAX][MAX];
bool seenx[MAX][MAX];
bool seenas[MAX][MAX];
vector<int> ans;
int R, C, cant = 0, cases;

void dfs2(int x, int y) {
    seenx[x][y] = true;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if(abs(i) + abs(j) != 1) continue;
            int nx = x + i;
            int ny = y + j;
            if(nx >= 0 && ny >= 0 && nx < R && ny < C && !seenx[nx][ny] && board[nx][ny] == 'X')
                dfs2(nx, ny);
        }
}

void dfs1(int x, int y) {
    seenas[x][y] = true;

    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if(abs(i) + abs(j) != 1) continue;
            int nx = x + i;
            int ny = y + j;
            if(nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if(board[nx][ny] == 'X' && !seenx[nx][ny]) {
                    dfs2(nx, ny);
                    cant++;
                }
                if((board[nx][ny] == '*' || board[nx][ny] == 'X') && !seenas[nx][ny])
                    dfs1(nx, ny);
            }
        }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    while(scanf("%d%d", &C, &R) > 0 && (R != 0 || C != 0)) {
        ans.clear();
        memset(seenx, false, sizeof(seenx));
        memset(seenas, false, sizeof(seenas));

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                scanf(" %c", &board[i][j]);

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++) {
                if(board[i][j] == '*' && !seenas[i][j]) {
                    cant = 0;
                    dfs1(i, j);
                    ans.PB(cant);
                }
            }

        sort(ans.begin(), ans.end());

        printf("Throw %d\n", ++cases);
        for(int i = 0; i < ans.size(); i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        cout << "\n\n";

    }



}
