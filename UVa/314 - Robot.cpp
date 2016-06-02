/* USER: 308958 (osdajigu) */
/* PROBLEM: 250 (314 - Robot) */
/* SUBMISSION: 14247575 */
/* SUBMISSION TIME: 2014-09-22 21:24:21 */
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
#define MAX 1000000 + 5
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

int firstMap[60][60];
int theMap[60][60];
int N, M, sX, sY, eX, eY, dd;
string face;
bool visited [60][60][5];
/**
  0 -> north up
  1 -> south down
  2 -> east derecha
  3 -> west izq
**/

/**               U  D   L  R  **/
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0,  1, -1};

struct Point {
    int x;
    int y;
    int d;
    int cost;
    Point() {}
    Point(int x, int y, int d, int cost) {
        this -> x = x;
        this -> y = y;
        this -> d = d;
        this -> cost = cost;
    }
    void print() {
        cout << x << " " << y << " " << d << " " << cost << endl;
    }
};

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < M - 1 && y < N - 1);
}

bool validate(int x, int y) {
    return (theMap[x][y] == 0);
}

void initializate(){
    memset(visited, false, sizeof(visited));
    memset(theMap, false, sizeof(theMap));
}

int solve() {
    int ans = INT_MAX;
    queue<Point> q;
    q.push(Point(sX, sY, dd, 0));
    while(!q.empty()) {
        Point p = q.front();
        q.pop();
        if(p.x == eX && p.y == eY)
            ans = min(ans, p.cost);
        if(visited[p.x][p.y][p.d])
            continue;
        visited[p.x][p.y][p.d] = true;
        //p.print();
        if(p.d == 0 || p.d == 1) {
            q.push(Point(p.x, p.y, 2, p.cost + 1));
            q.push(Point(p.x, p.y, 3, p.cost + 1));
        }
        if(p.d == 2 || p.d == 3) {
            q.push(Point(p.x, p.y, 0, p.cost + 1));
            q.push(Point(p.x, p.y, 1, p.cost + 1));
        }
        for(int i = 1; i <= 3; i++) {
            if (check(p.x + i * DX[p.d], p.y + i * DY[p.d])) {
                if (validate(p.x + i * DX[p.d], p.y + i * DY[p.d]))
                    q.push(Point(p.x + i * DX[p.d], p.y + i * DY[p.d], p.d, p.cost + 1));
                else
                    break;
            }
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
    cin >> M >> N;
    while(M != 0 || N != 0) {
        initializate();
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                cin >> firstMap[i][j];

        for(int i = 0; i < M - 1; i++) {
            for(int j = 0; j < N - 1; j++) {
                if(firstMap[i][j] == 1 || firstMap[i + 1][j] == 1 || firstMap[i][j + 1] == 1 || firstMap[i + 1][j + 1] == 1) {
                    theMap[i][j] = 1;
                }
                else
                    theMap[i][j] = 0;
            }
        }
        cin >> sX >> sY >> eX >> eY >> face;
        if(face == "north") dd = 0;
        if(face == "south") dd = 1;
        if(face == "east") dd = 2;
        if(face == "west") dd = 3;
        sX--;
        sY--;
        eX--;
        eY--;
        solve();
        cin >> M >> N;
    }
    return 0;
}
