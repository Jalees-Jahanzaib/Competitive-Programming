#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 30;
const double EPS = 1e-5;
const int INF = INT_MAX/2;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int n, T, ans, best_mask;
int p[MAX], t[MAX], d[MAX];
int c[MAX][MAX];
int dp[1<<20][MAX];

int get_ans(int mask) {
    int points = 0;
    for(int i = 0; i < n; i++) {
        if((mask>>i)&1) {
            points += p[i];
        }
    }
    return points;
}

int go(int mask, int pos) {
    int &r = dp[mask][pos];
    if(r == -1) {
        r = INF;
        if(__builtin_popcount(mask) == 1) {
            r = c[n][pos] + t[pos];
        }
        for(int i = 0; i < n; i++) {
            if(i != pos && (mask>>i)&1) {
                r = min(r, go(mask^(1<<pos), i) + c[i][pos] + t[pos]);
            }
        }
        if(r > d[pos]) r = INF;
        else {
            if(r + c[pos][n+1] <= T) {
                int x = get_ans(mask);
                if(ans < x) {
                    ans = x;
                    best_mask = mask;
                } else if(ans == x) {
                    best_mask = min(best_mask, mask);
                }
            }
        }

    }
    return r;
}

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

    while(cin >> n >> T) {
        for(int i = 0; i < n; i++) {
            cin >> p[i] >> t[i] >> d[i];
            if(d[i] == -1) d[i] = INT_MAX;
        }
        for(int i = 0; i < n+2; i++) {
            for(int j = 0; j < n+2; j++) {
                cin >> c[i][j];
            }
        }
        ans = 0, best_mask = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++) {
            go((1<<n)-1, i);
        }
        if(best_mask == INT_MAX) best_mask = 0;
        cout << ans << "\n";
        bool first = true;
        for(int i = 0; i < n; i++) {
            if((best_mask>>i)&1) {
                if(!first) cout << " ";
                cout << i+1;
                first = false;
            }
        }
        cout << "\n";

    }
}
