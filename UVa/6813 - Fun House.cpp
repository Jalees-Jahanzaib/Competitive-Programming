#include <bits/stdc++.h>

#define PB push_back
#define ii pair< ll, ll >
#define state pair< int, ii >
#define MAX 1010
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

string board[50];

const int DX[] = {-1,0,1,0};
const int DY[] = {0,1,0,-1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cases = 0;
    int n, m;
    while(cin >> n >> m && (n + m) != 0) {
        swap(n, m);
        int x, y;
        int dir;
        for(int i = 0; i < n; i++) {
            cin >> board[i];
            int pos = board[i].find('*');
            if(pos != -1) {
                x = i; y = pos;
                if(x == 0) dir = 2;
                if(x == n-1) dir = 0;
                if(y == 0) dir = 1;
                if(y == m-1) dir = 3;
            }
        }
        //cout << x << " " << y << " " << dir << endl;
        while(x >= 0 && x < n && y >= 0 && y < m) {
            x += DX[dir];
            y += DY[dir];
            //cout << x << " " << y << " " << dir << endl;
            //system("pause");
            if(board[x][y] == 'x') break;
            if(board[x][y] == '/') {
                if(dir == 0) dir = 1;
                else if(dir == 1) dir = 0;
                else if(dir == 2) dir = 3;
                else if(dir == 3) dir = 2;
            }
            if(board[x][y] == '\\') {
                if(dir == 0) dir = 3;
                else if(dir == 1) dir = 2;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 0;
            }
        }

        board[x][y] = '&';

        cout << "HOUSE " << ++cases << "\n";

        for(int i = 0; i < n; i++) cout << board[i] << "\n";
    }







}
