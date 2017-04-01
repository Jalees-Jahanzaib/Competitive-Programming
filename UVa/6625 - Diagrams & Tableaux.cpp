#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 10;
const double EPS = 1e-5;
const int INF = INT_MAX;
const ll MOD = int(1e9) + 7;

const int DX[] = {1, -1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int p[MAX][MAX];
int l[MAX], n, k, ans;
int cnt[MAX];

void go(int r, int c) {
    if(c == l[1]+1) {
        ans++;
        return;
    }

    for(int i = max(p[r][c-1], p[r-1][c]+1); i <= k; i++) {
        if(k-i >= cnt[c]-r) {
            p[r][c] = i;
            if(r == cnt[c])
                go(1, c+1);
            else
                go(r+1, c);
        }
    }
}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

    while(cin >> n) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; i++) {
            cin >> l[i];
            for(int j = 1; j <= l[i]; j++) {
                cnt[j]++;
            }
        }
        cin >> k;

        ans = 0;
        go(1, 1);

        cout << ans << "\n";
    }

}
