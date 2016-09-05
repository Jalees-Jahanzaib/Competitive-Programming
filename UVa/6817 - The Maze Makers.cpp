#include <bits/stdc++.h>

#define PB push_back
#define ii pair< ll, ll >
#define state pair< int, ii >
#define MAX 60
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

#define UP 3
#define RIGHT 2
#define DOWN 1
#define LEFT 0

using namespace std;

const int DX[] = {0,1,0,-1};
const int DY[] = {-1,0,1,0};

int board[MAX][MAX];
bool seen[MAX][MAX];

int get(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    while(cin >> n >> m && (n + m) != 0) {
        memset(seen, false, sizeof seen);
        queue<int> q;
        bool added = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char x; cin >> x;
                x = get(x);
                board[i][j] = x;
                //cout << int(x) << " ";
                if(added) continue;
                if( i == 0 && !((x>>UP)&1)) {
                    q.push(i); q.push(j); added = true;
                    seen[i][j] = true;
                    board[i][j] |= (1<<UP);
                    //cout << "up" << endl;
                }
                else if( j == 0 && !((x>>LEFT)&1)) {
                    q.push(i); q.push(j); added = true;
                    seen[i][j] = true;
                    board[i][j] |= (1<<LEFT);
                    //cout << "left" << endl;
                }
                else if( i == n-1 && !((x>>DOWN)&1)) {
                    q.push(i); q.push(j); added = true;
                    seen[i][j] = true;
                    board[i][j] |= (1<<DOWN);
                    //cout << "down" << endl;
                }
                else if( j == m-1 && !((x>>RIGHT)&1)) {
                    q.push(i); q.push(j); added = true;
                    seen[i][j] = true;
                    board[i][j] |= (1<<RIGHT);
                    //cout << "right" << endl;
                    //cout << board[i][j] << endl;
                }
            }
            //cout << endl;
        }
        bool solvable = false;
        int reached = 0;
        bool paths = false;
        q.push(-1);
        q.push(-1);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            int px = q.front(); q.pop();
            int py = q.front(); q.pop();
            //cout << x << " " << y << endl;
            //cout << board[x][y] << endl;
            reached++;

            for(int i = 0; i < 4; i++) {
                int nx = x + DX[i];
                int ny = y + DY[i];
                if((board[x][y]>>i)&1) continue;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    //cout << x << " --" << y << endl;
                    //cout << nx << "----" << ny << endl;
                    solvable = true;
                    continue;
                }
                if(nx == px && ny == py) continue;
                if(seen[nx][ny]) {
                    paths = true;
                    continue;
                }

                seen[nx][ny] = true;
                q.push(nx); q.push(ny);
                q.push(x); q.push(y);
            }
        }

        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!seen[i][j]) cout << i << " - " << j << endl;
            }
        }*/
        //cout << reached << endl;
        if(!solvable) cout << "NO SOLUTION\n";
        else if(reached != n*m) cout << "UNREACHABLE CELL\n";
        else if(paths) cout << "MULTIPLE PATHS\n";
        else cout << "MAZE OK\n";

    }

}
