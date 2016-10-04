#include<bits/stdc++.h>

#define MAX 50

using namespace std;

const int DXM[] = {-1,1,0,0};
const int DYM[] = {0,0,1,-1};
const int DXG[] = {-1,1,0,0};
const int DYG[] = {0,0,-1,1};

struct State {
    int mx, my, gx, gy, cost;
    State(int mx, int my, int gx, int gy, int cost) : mx(mx), my(my), gx(gx), gy(gy), cost(cost) {}
};

int r, c, label;
string board[MAX];

int seen[MAX][MAX][MAX][MAX];

bool check(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c && board[x][y] == '.';
}

int bfs(int a, int b, int c, int d, int lx, int ly) {
    queue<State> q;
    q.push(State(a, b, c, d, 0));
    seen[a][b][c][d] = seen[c][d][a][b] = label;
    while(!q.empty()) {
        State cur = q.front(); q.pop();
        if(cur.mx == cur.gx && cur.my == cur.gy && cur.mx == lx && cur.my == ly)
            return cur.cost;

        for(int i = 0; i < 4; i++) {
            int nmx = cur.mx + DXM[i];
            int nmy = cur.my + DYM[i];
            int ngx = cur.gx + DXG[i];
            int ngy = cur.gy + DYG[i];
            if(!check(nmx, nmy)) {
                nmx = cur.mx;
                nmy = cur.my;
            }
            if(!check(ngx, ngy)) {
                ngx = cur.gx;
                ngy = cur.gy;
            }

            if(seen[nmx][nmy][ngx][ngy] != label) {
                seen[nmx][nmy][ngx][ngy] = seen[ngx][ngy][nmx][nmy] = label;
                q.push(State(nmx, nmy, ngx, ngy, cur.cost + 1));
            }
        }
    }

    return -1;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> r >> c) {
        label++;
        int lx, ly, mx, my, gx, gy;
        cin >> lx >> ly >> mx >> my >> gx >> gy;
        lx--; ly--; mx--; my--; gx--; gy--;
        for(int i = 0; i < r; i++) {
            cin >> board[i];
        }

        int ans = bfs(mx, my, gx, gy, lx, ly);
        if(ans == -1) cout << "NO LOVE\n";
        else cout << ans << "\n";
    }
}
