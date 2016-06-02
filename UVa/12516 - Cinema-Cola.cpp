#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 120
#define INF INT_MAX / 4
#define ll long long
#define LEFT 1
#define RIGHT 2

using namespace std;

int n, b, col, all[MAX][MAX], p, R, C;
char row, c;
vector<ii> v;

int main () {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin);

    while(cin >> R >> C && (R != 0 || C != 0)) {
        memset(all, 0, sizeof all),

        cin >> p;
        for(int i = 0; i < p; i++) {
            cin >> row >> col >> c;
            row -= 'A';
            if(c == '-') all[row][col] |= LEFT, all[row][col - 1] |= RIGHT;
            else all[row][col] |= RIGHT, all[row][col + 1] |= LEFT;
        }

        cin >> p;
        v.clear();
        for(int i = 0; i < p; i++) {
            cin >> row >> col;
            row -= 'A';
            v.PB(ii(row, col));
        }

        sort(v.begin(), v.end());

        bool ok = true;
        for(int i = 0; i < p; i++) {
            row = v[i].first; col = v[i].second;
            if(!(all[row][col] & LEFT)) all[row][col] |= LEFT, all[row][col - 1] |= RIGHT;
            else if(!(all[row][col] & RIGHT)) all[row][col] |= RIGHT, all[row][col + 1] |= LEFT;
            else {
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }

}
