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
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] == board[x][y]
#define MAX 100 + 10
#define INF 0xfffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

int board[MAX][MAX];
bool seen[MAX][MAX], rows[MAX];
int R, C, nTest, n;

void dfs(int x, int y) {
    seen[x][y] = true;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if(abs(i) + abs(j) != 1) continue;
            int x_ = x + i;
            int y_ = y + j;
            if(check)
                dfs(x_, y_);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n && n != 0) {
        memset(seen, false, sizeof(seen));
        memset(rows, false, sizeof(rows));
        memset(board, 0, sizeof(board));
        cin.ignore();

        int x, y;
        string s;
        for(int i = 1; i < n; i++) {
            getline(cin, s);
            istringstream ss(s);
            while(ss >> x >> y) board[x][y] = i;
        }

        R = C = n + 1;

        bool ok = true;
        for(int i = 1; i < R; i++) {
            for(int j = 1; j < C; j++)
                if(!seen[i][j]) {
                    if(rows[board[i][j]]) {
                        ok = false;
                        break;
                    }
                    dfs(i, j);
                    rows[board[i][j]] = true;
                }
            if(!ok) break;
        }

        if(ok) cout << "good\n";
        else cout << "wrong\n";
    }

}



