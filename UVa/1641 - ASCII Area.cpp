#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)
    int R, C;
    while(cin >> R >> C) {
        string board[C + 10];

        for(int i = 0; i < R; i++) cin >> board[i];

        bool open = false;
        double ans = 0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(board[i][j] != '.'){
                    ans += 0.5;
                    open = !open;
                }
                else if(open) ans += 1;

        cout << int(ans) << "\n";
    }



}
