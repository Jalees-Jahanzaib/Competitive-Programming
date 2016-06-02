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
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] != '0'
#define MAX 1000 + 10
#define INF 0xfffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

string board[30];
bool seen[30][30];
int R, C, nTest;

int dfs(int x, int y) {
    int ans = 1;
    seen[x][y] = true;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            int x_ = x + i;
            int y_ = y + j;
            if(check)
                ans += dfs(x_, y_);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> nTest;
    cin.ignore();
    getline(cin, board[0]);

    bool first = true;

    while(nTest--) {
        if(first) first = false;
        else cout << "\n";

        memset(seen, false, sizeof(seen));

        int i = 0;
        while(getline(cin, board[i]) && board[i++] != "");

        R = --i;
        C = board[0].size();

        int ans = 0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(!seen[i][j] && board[i][j] == '1') {
                    ans = max(ans, dfs(i, j) - 1);
                }

        cout << ans << "\n";

    }

}



