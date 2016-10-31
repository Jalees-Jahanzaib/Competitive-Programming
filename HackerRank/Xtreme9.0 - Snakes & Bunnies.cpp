#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = INT_MAX;
const int MAX = 110;

const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

unordered_map<char, vector<ii>> snakes, bunnies;
string board[MAX];
int label[MAX][MAX];
vector<ii> pos;
int n, m, turn = -1;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool is_bussy(int x, int y) {
    for(int i = 0; i < m; i++) {
        if(i == turn) continue;
        if(x == pos[i].first && y == pos[i].second)
            return true;
    }
    return false;
}

void move_next(int &x, int &y, int &moves) {
    if(x == -1 && y == -1) {
        x++; y++;
        moves--;
    }
    else {
        moves--;
        for(int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if(check(nx, ny) && label[x][y] + 1 == label[nx][ny]) {
                x = nx; y = ny;
                break;
            }
        }
    }

    if(moves == 0) {
        if(board[x][y] >= '0' && board[x][y] <= '9') {
            if( x == bunnies[ board[x][y] ][0].first && y == bunnies[ board[x][y] ][0].second ) {
                int tmp = x;
                x = bunnies[ board[x][y] ][1].first;
                y = bunnies[ board[tmp][y] ][1].second;
            }
        }
        else if(board[x][y] >= 'a' && board[x][y] <= 'z') {
            if( x == snakes[ board[x][y] ][0].first && y == snakes[ board[x][y] ][0].second ) {
                int tmp = x;
                x = snakes[ board[x][y] ][1].first;
                y = snakes[ board[tmp][y] ][1].second;
            }
        }
        if(is_bussy(x, y)) moves++;
    }
}

bool make_move(int &x, int &y, int &moves) {
    int cycle = 100;
    while(moves && cycle--) {
        move_next(pos[turn].first, pos[turn].second, moves);
    }
    if(cycle <= 0) {
        cout << "PLAYER " << turn + 1 << " WINS BY EVIL CYCLE!\n";
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;

    for(int i = 0, cnt = 0; i < n; i++) {
        for(int j = (i % 2 == 0 ? 0 : n - 1); j >= 0 && j < n; (i % 2 == 0 ? j++ : j--)) {
            label[i][j] = ++cnt;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        cin >> board[i];
        for(int j = 0; j < n; j++) {
            char c = board[i][j];
            if(c >= 'a' && c <= 'z') {
                snakes[ c ].push_back( ii(i, j) );
                if(snakes[ c ].size() > 1) {
                    if(label[ snakes[ c ][0].first ][ snakes[ c ][0].second ] <
                       label[ snakes[ c ][1].first ][ snakes[ c ][1].second ])
                        swap(snakes[ c ][0], snakes[ c ][1]);
                }
            }
            if(c >= '0' && c <= '9') {
                bunnies[ c ].push_back( ii(i, j) );
                if(bunnies[ c ].size() > 1) {
                    if(label[ bunnies[ c ][0].first ][ bunnies[ c ][0].second ] >
                       label[ bunnies[ c ][1].first ][ bunnies[ c ][1].second ])
                        swap(bunnies[ c ][0], bunnies[ c ][1]);
                }
            }
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        pos.push_back(ii(-1, -1));
    }

    vector<int> dies;
    int x;
    while(cin >> x) {
        dies.push_back(x);
    }

    for(int i = 0; i < dies.size(); i += 2) {
        turn = (turn + 1) % m;
        int numMoves = dies[i] + dies[i+1];
        if(!make_move(pos[turn].first, pos[turn].second, numMoves)) {
            return 0;
        }
        if(dies[i] == dies[i+1]) {
            numMoves = dies[i+2];
            ++i;
            if(!make_move(pos[turn].first, pos[turn].second, numMoves)) {
                return 0;
            }
        }
        if(label[ pos[turn].first ][ pos[turn].second ] == n*n) break;
    }

    vector<int> all;
    for(int i = 0; i < m; i++) {
        all.push_back( label[ pos[i].first ][ pos[i].second ] );
    }

    for(int i = 0; i < m; i++) {
        if(i) cout << " ";
        cout << all[i];
    }
    cout << "\n";

}
