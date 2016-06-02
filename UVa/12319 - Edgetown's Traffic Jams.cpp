#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e2 + 10)
#define INF INT_MAX / 30
#define ll long long
#define LEFT 1
#define RIGHT 2
#define gauss(x) (x)*(x+1)/2

using namespace std;

int A, B, d[MAX][MAX], nd[MAX][MAX], n;
string line;

int main () {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);
    cout.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n && n != 0) {
        memset(d, 63, sizeof(d));
        memset(nd, 63, sizeof(nd));

        getline(cin, line);
        int from, to;
        for(int i = 0; i < n; i++) {
            getline(cin, line);
            istringstream ss(line);
            ss >> from;
            d[from][from] = 0;
            while(ss >> to) d[from][to] = 1;
        }

        for(int i = 0; i < n; i++) {
            getline(cin, line);
            istringstream ss(line);
            ss >> from;
            nd[from][from] = 0;
            while(ss >> to) nd[from][to] = 1;
        }

        cin >> A >> B;

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    nd[i][j] = min(nd[i][j], nd[i][k] + nd[k][j]);
                }

        bool ok = true;
        for(int i = 1; i <= n && ok; i++)
            for(int j = 1; j <= n && ok; j++) {
                ok &= (nd[i][j]) <= (A * d[i][j] + B);
            }

        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
