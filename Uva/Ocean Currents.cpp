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
#define MAX 1000 + 5
#define LIMIT 1000000
#define MOD 1000000007

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8

using namespace std;

int R, C, sX, sY, eX, eY, nTest;
char theMap[MAX][MAX];
int visited[MAX][MAX];

///                0   1  2  3  4   5   6   7
const int DX[] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int DY[] = { 0,  1, 1, 1, 0, -1, -1, -1};

struct Point{
    int x;
    int y;
    int cost;
    char dir;

    Point() {}

    Point(int x, int y, int cost, char dir) {
        this -> x = x;
        this -> y = y;
        this -> cost = cost;
        this -> dir = dir;
    }

    bool operator < (const Point &o) const {
        return this -> cost > o.cost;
    }

    void print() {
        cout << x << " " << y << " " << cost << endl;
    }
};


bool check(int x, int y) {
    return (x >= 1 && y >= 1 && x <= R && y <= C);
}

int solve() {
    priority_queue<Point> q;
    q.push(Point(sX, sY, 0, theMap[sX][sY]));
    while(!q.empty()) {
        Point p = q.top();
        q.pop();
        if(p.x == eX && p.y == eY) {
            return p.cost;
        }

        for(int i = 0; i < 8; i++) {
            if(check(p.x + DX[i], p.y + DY[i])) {
                Point a(p.x + DX[i], p.y + DY[i], (p.dir - '0'  == i ? p.cost : p.cost + 1), theMap[p.x + DX[i]][p.y + DY[i]]);
                if(visited[a.x][a.y] > a.cost || visited[a.x][a.y] == -1) {
                    q.push(a);
                    visited[a.x][a.y] = a.cost;
                }
            }
        }
    }
}


int main() {

    cin >> R >> C;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= R; j++) {
            cin >> theMap[i][j];
        }
    }

    cin >> nTest;

    while(nTest--) {
        cin >> sX >> sY >> eX >> eY;
        memset(visited, -1, sizeof(visited));
        cout << solve() << endl;
    }
}

