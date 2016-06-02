#include<bits/stdc++.h>

#define ll long long
#define ii pair<ll, ll>
#define PB push_back
#define MAX 2 * (int(1e5) + 10)
#define INF 0x3fffffff
#define INF2 1ll << 62
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

const int costs[][5] = { {7, 6, 5, 6, 7},
                       {6, 3, 2, 3, 6},
                       {5, 2, 0, 2, 5},
                       {6, 3, 2, 3, 6},
                       {7, 6, 5, 6, 7} };
int n, m, d[1010][1010], sx, sy, fx, fy, w;

struct State {
    int x, y, cost;
    State(int x, int y, int cost) : x(x), y(y), cost(cost) {}

    bool operator < (const State &p) const {
        return cost > p.cost;
    }
};

void dijkstra() {
    priority_queue<State> q;
    q.push(State(sx, sy, 0));
    d[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.top().x;
        int y = q.top().y;
        int cost = q.top().cost; q.pop();
        //cout << x << " " << y << " " << cost << endl;

        if(d[x][y] != cost) continue;
        if(x == fx && y == fy) {
            cout << cost << "\n";
            return;
        }

        for(int i = -2; i <= 2; i++) {
            for(int j = -2; j <= 2; j++) {
                int nx = x + i, ny = y + j;
                if(!(nx >= 0 && ny >= 0 && nx < n && ny < m)) continue;
                int w = costs[2 + i][2 + j] + cost;
                if(d[nx][ny] > w) {
                    d[nx][ny] = w;
                    q.push(State(nx, ny, w));
                }
            }
        }
    }
    cout << "impossible\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    while(cin >> m >> n && (n + m) != 0) {
        cin >> sy >> sx >> fy >> fx;
        sy--; sx--; fx--; fy--;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                d[i][j] = INF;

        cin >> w;
        while(w--) {
            int a, b, c, dd;
            cin >> b >> a >> dd >> c;
            a--; b--; c--; dd--;
            for(int i = a; i <= c; i++)
                for(int j = b; j <= dd; j++)
                    d[i][j] = -1;
        }
        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << (d[i][j] == INF ? 1 : 0);
            cout << endl;
        }*/

        //cout << "ola k ase" << endl;

        dijkstra();
    }

}
