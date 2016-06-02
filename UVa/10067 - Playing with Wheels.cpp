/* USER: 308958 (osdajigu) */
/* PROBLEM: 1008 (10067 - Playing with Wheels) */
/* SUBMISSION: 14254784 */
/* SUBMISSION TIME: 2014-09-24 05:37:58 */
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
#define MAX 10 + 2
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

int sX, sY, sZ, sW, fX, fY, fZ, fW, auxX, auxY, auxZ, auxW, n, tCases;
bool visited[MAX][MAX][MAX][MAX];


const int DX[] = {1,0,0,0,-1,0,0,0};
const int DY[] = {0,1,0,0,0,-1,0,0};
const int DZ[] = {0,0,1,0,0,0,-1,0};
const int DW[] = {0,0,0,1,0,0,0,-1};

struct Number {
    int x;
    int y;
    int z;
    int w;
    int cost;
    Number() {}

    Number(int x, int y, int z, int w, int cost) {
        this -> x = x;
        this -> y = y;
        this -> z = z;
        this -> w = w;
        this -> cost = cost;
    }
};

int solve() {
    queue<Number> q;
    q.push(Number(sX, sY, sZ, sW, 0));
    while(!q.empty()) {
        Number n = q.front();
        q.pop();
        if(n.x == fX && n.y == fY && n.z == fZ && n.w == fW)
           return n.cost;
        if(visited[n.x][n.y][n.z][n.w])
            continue;
        visited[n.x][n.y][n.z][n.w] = true;
        for(int i = 0; i < 4; i++)
            q.push(Number((n.x + DX[i]) % 10, (n.y + DY[i]) % 10, (n.z + DZ[i]) % 10, (n.w + DW[i]) % 10, n.cost + 1));
        for(int i = 4; i < 8; i++)
            q.push(Number((n.x + DX[i] + 10) % 10, (n.y + DY[i] + 10) % 10, (n.z + DZ[i] + 10) % 10, (n.w + DW[i] + 10) % 10, n.cost + 1));
    }
    return -1;
}

void initializate() {
    memset(visited, false, sizeof(visited));
}

int main() {
    cin >> tCases;
    while(tCases--) {
        initializate();
        cin >> sX >> sY >> sZ >> sW;
        cin >> fX >> fY >> fZ >> fW;
        cin >> n;
        while(n--) {
            cin >> auxX >> auxY >> auxZ >> auxW;
            visited[auxX][auxY][auxZ][auxW] = true;
        }
        cout << solve() << endl;

    }

}
