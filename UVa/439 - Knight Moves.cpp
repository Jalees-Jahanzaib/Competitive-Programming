/* USER: 308958 (osdajigu) */
/* PROBLEM: 380 (439 - Knight Moves) */
/* SUBMISSION: 14248188 */
/* SUBMISSION TIME: 2014-09-22 23:46:02 */
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
#define MAX 10
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

bool visited[MAX][MAX];
string start, finish;
int sX, sY, fX, fY;

const int DX[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
const int DY[8] = {-1, 1, -1, 1, -2, -2, 2, 2};

struct Point {
    int x;
    int y;
    int cost;
    Point() {}
    Point(int x, int y, int cost) {
        this -> x = x;
        this -> y = y;
        this -> cost = cost;
    }
};

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

int solve() {
    queue<Point> q;
    q.push(Point(sX, sY, 0));
    while(!q.empty()) {
        Point p = q.front();
        q.pop();
        if(p.x == fX && p.y == fY)
            return p.cost;
        if(visited[p.x][p.y])
            continue;
        visited[p.x][p.y] = true;
        for(int i = 0; i < 8; i++) {
            if(check(p.x + DX[i], p.y + DY[i]))
                q.push(Point(p.x + DX[i], p.y + DY[i], p.cost + 1));
        }
    }
}

void initializate() {
    memset(visited, false, sizeof(visited));
}

int main() {
    while (cin >> start >> finish) {
        initializate();
        sX = start[0] - 'a';
        sY = start[1] - '0' - 1;
        fX = finish[0] - 'a';
        fY = finish[1] - '0' - 1;
        cout << "To get from " << start << " to " << finish << " takes " << solve() << " knight moves." << endl;
    }
}
