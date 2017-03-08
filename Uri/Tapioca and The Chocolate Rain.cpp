#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 100010;
const ll MOD = 1e9 + 7;

int DX[] = {0, 0, 1, -1};
int DY[] = {1, -1, 0, 0};

int dp[22][22][1005];
int seen[22][22][1005];

int go(int x, int y, int t) {
    if(t > 1000) return 0;
    int &r = dp[x][y][t];
    if(r == -1) {
        r = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if(nx >= 0 && nx <= 20 && ny >= 0 && ny <= 20) {
                r = max(r, go(nx, ny, t+1));
            }
        }
        r = max(r, go(x, y, t+1));
        r += seen[x][y][t];
    }
    return r;
}

int main() {
    memset(dp, -1, sizeof dp);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, t; cin >> x >> y >> t;
        seen[x][y][t]++;
    }

    cout << go(6, 6, 0) << "\n";


}
