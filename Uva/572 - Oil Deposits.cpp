/* USER: 308958 (osdajigu) */
/* PROBLEM: 513 (572 - Oil Deposits) */
/* SUBMISSION: 14248323 */
/* SUBMISSION TIME: 2014-09-23 01:11:11 */
/* LANGUAGE: 3 */

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
#include<utility>
#include<sstream>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define PB push_back
#define EPS 0.00000001
#define MAX 100 + 2
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
/**           X    Y                        **/
bool visited[MAX][MAX];
string theMap[MAX];
int m, n;
/**                                              **/
const int DX[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int DY[8] = { 0, 0,-1, 1, 1, -1, 1, -1};


struct Point {
    int x;
    int y;
    Point() {}
    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
    void print() {
        cout << x << " " << y << endl;
    }
};

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < m && y < n);
}
bool validate(int x, int y) {
    return (theMap[x][y] == '@');
}

void bfs(int x, int y) {
    queue<Point> q;
    q.push(Point(x, y));
    while(!q.empty()) {
        Point p = q.front();
        q.pop();
       // p.print();
        if(visited[p.x][p.y])
            continue;
        visited[p.x][p.y] = true;
        for(int i = 0; i < 8; i++)
            if(check(p.x + DX[i], p.y + DY[i]))
                if(validate(p.x + DX[i], p.y + DY[i]))
                    q.push(Point(p.x + DX[i], p.y + DY[i]));
    }
}

void initializate() {
    memset(visited, false, sizeof(visited));
}

int main() {
    cin >> m >> n;
    while (m != 0 || n != 0) {
        initializate();
        for(int i = 0; i < m; i++) {
            cin >> theMap[i];
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] || !validate(i, j))
                    continue;
                bfs(i, j);
                ans++;
               // cout << endl;
            }
        }
        cout << ans << endl;
        cin >> m >> n;
    }
}
