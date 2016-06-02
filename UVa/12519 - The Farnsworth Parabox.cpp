#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e2 + 10)
#define INF INT_MAX / 4
#define ll long long

using namespace std;

int d[MAX][MAX], n, b;

int main () {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin);

    while(cin >> n >> b && (n != 0 || b != 0)) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == j) d[i][j] = 0;
                else d[i][j] = INF;
            }
        }

        int from, to, dist;
        for(int i = 0; i < b; i++) {
            cin >> from >> to >> dist;
            d[from][to] = dist;
            d[to][from] = -dist;
        }

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


        bool ans = false;
        for(int i = 1; i <= n; i++)
            if(d[i][i] < 0)
                ans = true;

        if(ans) cout << "Y\n";
        else cout << "N\n";

    }

}
