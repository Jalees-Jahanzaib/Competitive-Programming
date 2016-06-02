/* USER: 308958 (osdajigu) */
/* PROBLEM: 869 (928 - Eternal Truths) */
/* SUBMISSION: 14252592 */
/* SUBMISSION TIME: 2014-09-23 18:06:57 */
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
#define MAX 300 + 2
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

int cases, C, R, sX, sY, fX, fY;
string theMap[MAX];
bool visited[MAX][MAX][5];
///          U  D  L  R
int DX[] = {-1, 1,  0, 0};
int DY[] = { 0, 0, -1, 1};

struct Point{
    int x;
    int y;
    int nMove;
    int cost;
    Point() {}

    Point(int x, int y, int nMove, int cost) {
        this -> x = x;
        this -> y = y;
        this -> nMove = nMove;
        this -> cost = cost;
    }

    void print() {
        cout << x << " " << y << " " << nMove << " " << cost << endl;
    }
};

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < R && y < C);
}

bool validate(int x, int y, int i, int nMoves) {
    for(int j = 1; j <= nMoves; j++)
        if(theMap[x + DX[i] * j][y + DY[i] * j] == '#')
            return false;
    return true;
}

void solve() {
    queue<Point> q;
    q.push(Point(sX, sY, 1, 0));
    while(!q.empty()) {
        Point p = q.front();
        q.pop();
        if(p.x == fX && p.y == fY) {
            cout << p.cost << endl;
            return;
        }
        if(visited[p.x][p.y][p.nMove])
            continue;
        visited[p.x][p.y][p.nMove] = true;
        //p.print();
        for(int i = 0; i < 4; i++)
            if(check(p.x + p.nMove * DX[i], p.y + p.nMove * DY[i]))
                if(validate(p.x , p.y , i, p.nMove))
                    q.push(Point(p.x + p.nMove * DX[i], p.y + p.nMove * DY[i], p.nMove % 3 + 1, p.cost + 1));
    }
    cout << "NO" << endl;
    return;
}

void initializate() {
    memset(visited, false, sizeof(visited));
}


int main() {
    cin >> cases;
    while(cases--) {
        initializate();
        cin >> R >> C;
        for(int i = 0; i < R; i++) {
            cin >> theMap[i];
            for(int j = 0; j < C; j++) {
                if(theMap[i][j] == 'S') {
                    sX = i;
                    sY = j;
                }
                if(theMap[i][j] == 'E') {
                    fX = i;
                    fY = j;
                }
            }
        }
        //cout << "S: " << sX << ", " << sY << endl;
        //cout << "F: " << fX << ", " << fY << endl;
        solve();
    }
}
