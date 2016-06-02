/* USER: 308958 (osdajigu) */
/* PROBLEM: 473 (532 - Dungeon Master) */
/* SUBMISSION: 15140764 */
/* SUBMISSION TIME: 2015-03-14 02:01:10 */
/* LANGUAGE: 3 */

#include<bits/stdc++.h>
#define PB push_back
#define MAX 50
#define check(x, y, z) x >= 0 && y >= 0 && z >= 0 && x < R && y < C && z < L && !seen[x][y][z]

using namespace std;

int L, R, C, start[4], end[4];
char board[MAX][MAX][MAX];
bool seen[MAX][MAX][MAX];

const int DX[] = {0,0,1,-1,0,0};
const int DY[] = {1,-1,0,0,0,0};
const int DZ[] = {0,0,0,0,1,-1};

struct Point{
    int x, y, z, cost;
    Point(int x, int y, int z, int cost) : x(x), y(y), z(z), cost(cost) {}
};

void bfs() {
    queue<Point> q;
    q.push(Point(start[0], start[1], start[2], 0));
    seen[start[0]][start[1]][start[2]] = true;
    while(!q.empty()) {
        Point p = q.front(); q.pop();
        if(p.x == end[0] && p.y == end[1] && p.z == end[2]) {
            printf("Escaped in %d minute(s).\n", p.cost);
            return;
        }
        for(int i = 0; i < 6; i++) {
            int x = p.x + DX[i];
            int y = p.y + DY[i];
            int z = p.z + DZ[i];
            int cost = p.cost + 1;
            if(check(x, y, z)) {
                seen[x][y][z] = true;
                q.push(Point(x, y, z, cost));
            }
        }
    }
    printf("Trapped!\n");
}

int main() {
    while(scanf("%d%d%d", &L, &R, &C) > 0 && L != 0 && R != 0 && C != 0) {
        memset(seen, 0, sizeof(seen));
        for(int k = 0; k < L; k++)
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++) {
                    scanf(" %c", &board[i][j][k]);
                    if(board[i][j][k] == 'S') start[0] = i, start[1] = j, start[2] = k;
                    if(board[i][j][k] == 'E') end[0] = i, end[1] = j, end[2] = k;
                    if(board[i][j][k] == '#') seen[i][j][k] = true;
                }
        bfs();
    }
}
