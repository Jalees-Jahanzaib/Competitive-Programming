/* USER: 308958 (osdajigu) */
/* PROBLEM: 1043 (10102 - The path in the colored field) */
/* SUBMISSION: 14263181 */
/* SUBMISSION TIME: 2014-09-25 15:28:16 */
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

int M;

const int DX[] = {1, -1, 0, 0};
const int DY[] = {0, 0, -1, 1};

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
    return (x >= 0 && y >= 0 && x < M && y < M );
}

int main() {

    while(cin >> M) {
        string theMap[M];
        bool visited[M][M];
        for(int i = 0; i < M; i++) {
            cin >> theMap[i];
        }
        int ans = 0;
        int aux = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < M; j++) {
                if(theMap[i][j] != '1')
                    continue;
                memset(visited, false, sizeof(visited));
                queue<Point> q;
                q.push(Point(i, j, 0));
                while(!q.empty()) {
                    Point p = q.front();
                    q.pop();
                    if(theMap[p.x][p.y] == '3') {
                        aux = p.cost;
                        break;
                    }
                    if(visited[p.x][p.y])
                        continue;
                    visited[p.x][p.y] = true;
                    for(int k = 0; k < 4; k++)
                        if(check(p.x + DX[k], p.y + DY[k]))
                            q.push(Point(p.x + DX[k], p.y + DY[k], p.cost + 1));
                }
                ans = max(ans, aux);
            }
        }
        cout << ans << endl;

    }

}
