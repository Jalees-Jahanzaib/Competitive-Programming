#includebitsstdc++.h

using namespace std;

typedef long long ll;

const int MAX = 20;
int dp[2][MAX][(1  MAX) + 2], seen[2][MAX][(1  MAX) + 2];
int d[MAX][MAX];

int cases;
const int INF = INT_MAX  3;
int n, m;

int go (int mask, int last, bool dst) {
    if (mask == 0) {
        if (dst == 0 && last == 0) return 0;
        if (dst == 1 && last == n - 1) return 0;
        return INF;
    }
    int &r = dp[dst][last][mask];
    int &s = seen[dst][last][mask];

    if (s != cases) {
        s = cases;
        r = INF;
        for (int i = 0; i  n; ++i) {
            if (mask  i & 1) {
                r = min(r, go(mask ^ 1  i, i, dst) + d[last][i]);
            }
        }
    }

    return r;
}

int main() {
    iossync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen(input.txt, r, stdin);
        freopen(output.txt, w, stdout);
    #else
        #define endl 'n'
    #endif  LOCAL

    while (cin  n  m) {
        int h = n - 2;
        ++cases;
        for (int i = 0; i  n; ++i)
            for (int j = 0; j  n; ++j)
                if (i != j)
                    d[i][j] = INF;

        for (int i = 0; i  m; ++i) {
            int u, v, t;
            cin  u  v  t;
            d[u][v] = d[v][u] = t;
        }

        for (int k = 0; k  n; ++k)
            for (int i = 0; i  n; ++i)
                for (int j = 0; j  n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        if (n == 3) {
            cout  Case   cases     2  (d[0][1] + d[1][2])  endl;
            continue;
        }

        int ans = INF;
        int lim = (1  n) - 1;
        for (int mask = 1; mask = lim; ++mask) {
            if (mask & 1  mask  n - 1 & 1) continue;
            if (__builtin_popcount(mask) == h  2) {
                for (int i = 0; i  n; ++i) {
                    if (!(mask  i & 1)) continue;
                    for (int j = 0; j  n; ++j)
                        if (mask  j & 1) {
                            int left1 = (mask ^ 1  i)  1;
                            int right1 = (~mask & lim) ^ 1;

                            int left2 = (~mask & lim) ^ 1  n - 1;
                            int right2 = (mask ^ 1  j)  1  n - 1;

                            int cur = go(left1, i, 0) + go(right1, i, 1) +
                                      go(right2, j, 1) + go(left2, j, 0);

                            ans = min(ans, cur);
                        }
                }
            }
        }

        cout  Case   cases     ans  endl;
    }
}