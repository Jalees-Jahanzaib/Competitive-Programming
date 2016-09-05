#include <bits/stdc++.h>

#define PB push_back
#define ii pair< ll, ll >
#define state pair< int, ii >
#define MAX 1010
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

const int DX[] = {0,0,-1,1};
const int DY[] = {1,-1,0,0};

int seen[MAX][MAX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int n, m, t, l, w;
    while(cin >> n && n != -1) {
        cin >> m >> t >> l >> w;
        memset(seen, false, sizeof seen);
        queue<int> q;
        for(int i = 0; i < l; i++) {
            int x, y; cin >> x >> y;
            q.push(x); q.push(y); q.push(1);
            seen[x][y] = true;
        }
        for(int k = 0; k < w; k++) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int dx = (x2-x1)/(abs(x2-x1) == 0 ? 1 : abs(x2-x1));
            int dy = (y2-y1)/(abs(y2-y1) == 0 ? 1 : abs(y2-y1));
            for(int i = x1, j = y1; i != x2 || j != y2; i += dx, j += dy) {
                seen[i][j] = true;
            }
            seen[x2][y2] = true;
        }

        int ans = 0;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            int d = q.front(); q.pop();

            ans++;

            for(int i = 0; i < 4; i++) {
                int nx = x + DX[i];
                int ny = y + DY[i];
                if(!(nx >= 1 && ny >= 1 && nx <= n && ny <= m)) continue;
                if(!seen[nx][ny] && d + 1 <= t) {
                    seen[nx][ny] = true;
                    q.push(nx);
                    q.push(ny);
                    q.push(d + 1);
                }
            }
        }
        cout << ans << "\n";

    }

}
