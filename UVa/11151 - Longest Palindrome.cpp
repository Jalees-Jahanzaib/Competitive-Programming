#include<bits/stdc++.h>

using namespace std;

const int INF = INT_MAX/2;

int dp[1010][1010];
string w;

int go(int i, int j) {
    if(i == j) return 1;
    if(j < i) return 0;
    if(i < 0 || j >= w.size()) return -INF;
    int &r = dp[i][j];

    if(r == -1) {
        r = max(r, go(i+1, j));
        r = max(r, go(i, j-1));
        r = max(r, go(i+1, j-1) + 2*(w[i] == w[j]));
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    while(n--) {
        memset(dp, -1, sizeof dp);
        getline(cin, w);
        cout << max(0, go(0, w.size() - 1)) << '\n';

    }
}
