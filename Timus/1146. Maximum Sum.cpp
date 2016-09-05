#include <bits/stdc++.h>

#define PB push_back
#define ii pair< int, int >
#define MAX 200
#define INF INT_MAX/2
#define ll long long
#define MOD 1000000007

using namespace std;

int board[MAX][MAX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    int mx = -INF;
    for(int i = 0; i < n; i++) {
        vector<int> v(n);
        for(int j = i; j < n; j++) {
            for(int k = 0; k < n; k++)
                v[k] += board[k][j];
            int cur = 0;
            for(int k = 0; k < n; k++) {
                cur += v[k];
                mx = max(mx, cur);
                if(cur < 0) cur = 0;
            }
        }
    }

    cout << mx << "\n";

}
