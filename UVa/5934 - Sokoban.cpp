#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 100;
const int INF = INT_MAX/3;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

string board[MAX];

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

inline int get_dir(char c) {
    if(c == 'U') return 0;
    if(c == 'R') return 1;
    if(c == 'D') return 2;
    return 3;
}

int n, m;

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool update1(int x, int y) {
    if(board[x][y] == 'W') board[x][y] = '+';
    else board[x][y] = '.';
}

bool update2(int x, int y) {
    if(board[x][y] == '+') board[x][y] = 'W';
    else board[x][y] = 'w';
}

bool update22(int x, int y) {
    if(board[x][y] == 'B') board[x][y] = 'W';
    else board[x][y] = 'w';
}

bool update3(int x, int y) {
    if(board[x][y] == '+') board[x][y] = 'B';
    else board[x][y] = 'b';
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    while(cin >> n >> m && (n+m != 0) ) {
        int px, py, done = 0, total = 0;
        for(int i = 0; i < n; i++) {
            cin >> board[i];
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'W' || board[i][j] == 'w')
                    px = i, py = j;
                if(board[i][j] == 'B') done++, total++;
                if(board[i][j] == 'b') total++;
            }
        }

        string command; cin >> command;

        for(int i = 0; i < command.size(); i++) {
            int dir = get_dir(command[i]);
            int nx1 = px + DX[dir], ny1 = py + DY[dir];
            int nx2 = px + 2*DX[dir], ny2 = py + 2*DY[dir];
            if(!ok(nx1, ny1) || board[nx1][ny1] == '#') continue;
            if(board[nx1][ny1] == 'B' || board[nx1][ny1] == 'b') {
                if(!ok(nx2, ny2)) continue;
                if(board[nx2][ny2] != '+' && board[nx2][ny2] != '.' ) continue;
            }

            if(board[nx1][ny1] == 'b' || board[nx1][ny1] == 'B') {
                char last = board[nx1][ny1];
                update1(px, py);
                update22(nx1, ny1);
                update3(nx2, ny2);
                if(last == 'B' && board[nx2][ny2] == 'b') done--;
                if(last == 'b' && board[nx2][ny2] == 'B') done++;
            } else {
                update1(px, py);
                update2(nx1, ny1);
            }
            px = nx1; py = ny1;
            if(done == total) break;
        }

        cout << "Game " << ++cases << ": " << (done == total ? "complete" : "incomplete") << "\n";
        for(int i = 0; i < n; i++) {
            cout << board[i] << "\n";
        }
    }

}

