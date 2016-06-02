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
#define MAX 1000 + 10
#define INF 0xfffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

int R, C, sx, sy, fx, fy, rows, col, rowNumber, cant;
bool seen[MAX][MAX];

int bfs() {
    queue<int> q;
    q.push(sx); q.push(sy); q.push(0);
    seen[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int c = q.front(); q.pop();

        if(x == fx && y == fy) return c;

        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) {
                if(abs(i) + abs(j) != 1) continue;
                int x_ = x + i;
                int y_ = y + j;
                if(check) {
                    seen[x_][y_] = true;
                    q.push(x_);
                    q.push(y_);
                    q.push(c + 1);
                }
            }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> R >> C && (R != 0 || C != 0)) {
        memset(seen, false, sizeof seen);

        cin >> rows;
        while(rows--) {
            cin >> rowNumber >> cant;
            while(cant--) cin >> col, seen[rowNumber][col] = true;
        }

        cin >> sx >> sy >> fx >> fy;

        cout << bfs() << "\n";
    }
}



