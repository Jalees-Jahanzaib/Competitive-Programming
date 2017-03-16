//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX/2;
const int MAX = 6005;

int cost[MAX], dp[MAX][2];
vector< vector<int> > G;

int go(int u, int p, int going) {
    int &r = dp[u][going];
    if(r != -1) return r;

    r = going ? cost[u] : 0;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == p) continue;
        go(v, u, 0); go(v, u, 1);
        if(going) r += dp[v][0];
        else r += max(dp[v][0], dp[v][1]);
    }

    return r;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    memset(dp, -1, sizeof dp);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    G = vector< vector<int> > (n+1);
    int a, b;
    while(cin >> a >> b && (a+b)) {
        G[b].push_back(a);
        G[a].push_back(b);
//        cout << a << " - " << b << endl;
    }

    go(1, -1, 0);
    go(1, -1, 1);

    cout << max(dp[1][0], dp[1][1]) << "\n";



}
