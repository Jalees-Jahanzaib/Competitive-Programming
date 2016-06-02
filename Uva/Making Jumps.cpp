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
#define ii pair<int, int>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] != '#'
#define MAX 100000 + 10
#define INF 1LL<<60
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

int R, from, amount, C, cases, all;
bool board[12][12];

int dfs(int x, int y) {
    int ans = 1;
    for(int i = -2; i <= 2; i++)
        for(int j = -2; j <= 2; j++) {
            if(abs(i) + abs(j) != 3) continue;
            int newX = x + i;
            int newY = y + j;
            if(newX >= 0 && newY >= 0 && newX < R && newY < C && !board[newX][newY]) {
                board[newX][newY] = true;
                ans = max(ans, dfs(newX, newY) + 1);
                board[newX][newY] = false;
            }
        }

    return ans;
}

int main() {
    while(scanf("%d", &R) > 0 && R != 0) {
        memset(board, true, sizeof(board));

        C = -1, all = 0;
        for(int i = 0; i < R; i++) {
            scanf("%d %d", &from, &amount);
            all += amount;
            C = max(C, from + amount);
            for(int j = 0; j < amount; j++)
                board[i][j + from] = false;
        }

        bool flag = true;
        int ans;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                if(!board[i][j]) {
                    board[i][j] = true;
                    ans = dfs(i, j);
                    flag = false;
                    break;
                }
            if(!flag) break;
        }

        ans = all - ans;
        if(ans == 1) printf("Case %d, %d square can not be reached.\n", (++cases), ans);
        else printf("Case %d, %d squares can not be reached.\n", (++cases), ans);

    }

}

