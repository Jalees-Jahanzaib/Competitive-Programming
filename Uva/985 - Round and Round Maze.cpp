/* USER: 308958 (osdajigu) */
/* PROBLEM: 926 (985 - Round and Round Maze) */
/* SUBMISSION: 14253400 */
/* SUBMISSION TIME: 2014-09-23 20:49:54 */
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
#define MAX 500 + 2
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
int sX = 0, sY = 0, fX, fY, C, R;
string s;
int theMap[MAX][MAX];
bool visited[MAX][MAX][5];
/**
 * 1000 = 8 -> Up
 * 0100 = 4 -> Right
 * 0010 = 2 -> Down
 * 0001 = 1 -> Left
*/

///          U  D   L  R
int DX[4] = {-1, 1,  0, 0};
int DY[4] = { 0, 0, -1, 1};
int DIR[4] = { 8, 2, 1, 4};

/**
 * 0 -> 0°
 * 1 -> 90°
 * 2 -> 180°
 * 3 -> 270°
 */

struct Point {
    int x;
    int y;
    int nRotate;
    int cost;
    Point() {}
    Point(int x, int y, int nRotate, int cost) {
        this -> x = x;
        this -> y = y;
        this -> nRotate = nRotate;
        this -> cost = cost;
    }

    void print() {
        cout << x << " " << y << " nRotate = " << nRotate << " " << cost << endl;
    }
};

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < R && y < C);
}

int rotate(int x, int y, int n) {
    int aux = theMap[x][y];
    for(int i = 0; i < n; i++) {
        if(aux&1) {
             aux = (aux >> 1) + 8;
             //cout << "entre a rotar impar" << endl;
        }
        else {
            aux = aux >> 1;
            //cout << "entre a rotar par" << endl;
        }
    }
    //cout << "Map[x][y]=: " << theMap[x][y] << "  ->  " << aux << endl;
    return aux;
}

void solve() {
    queue<Point> q;
    q.push(Point(sX, sY, 0, 0));
    while(!q.empty()) {
        Point p = q.front();
        q.pop();
        //p.print();
        if(p.x == fX && p.y == fY) {
            cout << p.cost << endl;
            return;
        }
        if(visited[p.x][p.y][p.nRotate])
            continue;
        visited[p.x][p.y][p.nRotate] = true;
        for(int i = 0; i < 4; i++)
            if(check(p.x + DX[i], p.y + DY[i]))
                if(rotate(p.x, p.y, p.nRotate)&DIR[i])
                    q.push(Point(p.x + DX[i], p.y + DY[i], (p.nRotate + 1) % 4, p.cost + 1));
    }
    cout << "no path to exit" << endl;
}




void initializate() {
    memset(visited, false, sizeof(visited));
    memset(theMap, 0, sizeof(theMap));
}


int main() {
    while(cin >> R >> C) {
        initializate();
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(i == R - 1 && j == C - 1) {
                    fX = i;
                    fY = j;
                }
                else {
                    cin >> s;
                    for(int k = 0; k < s.size(); k++) {
                        if(s[k] == 'N') theMap[i][j] |= 8;
                        if(s[k] == 'E') theMap[i][j] |= 4;
                        if(s[k] == 'S') theMap[i][j] |= 2;
                        if(s[k] == 'W') theMap[i][j] |= 1;
                    }
                }
            }
        }
        /*cout << "S:" << sX << " " << sY << endl;
        cout << "F:" << fX << " " << fY << endl;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                cout << theMap[i][j] << " ";
            cout << endl;
        }*/
        solve();
    }
}
