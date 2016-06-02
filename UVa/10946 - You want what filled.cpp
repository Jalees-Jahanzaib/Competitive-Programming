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
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] == board[x][y]
#define MAX 50 + 10
#define INF 0xfffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

string board[MAX];
bool seen[MAX][MAX];
int R, C, nTest, cases;

int dfs(int x, int y) {
    int ans = 1;
    seen[x][y] = true;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if(abs(i) + abs(j) != 1) continue;
            int x_ = x + i;
            int y_ = y + j;
            if(check)
                ans += dfs(x_, y_);
        }

    return ans;
}

bool cmp(ii a, ii b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> R >> C && (R != 0 || C != 0)) {
        memset(seen, false, sizeof(seen));
        for(int i = 0; i < R; i++) cin >> board[i];

        vector<ii> ans;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(!seen[i][j] && board[i][j] != '.')
                    ans.PB(ii(dfs(i, j), board[i][j]));

        sort(ans.rbegin(), ans.rend(), cmp);

        cout << "Problem " << ++cases << ":\n";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i].second << " " << ans[i].first << "\n";
    }

}



