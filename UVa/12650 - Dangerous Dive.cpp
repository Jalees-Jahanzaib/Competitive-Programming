#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 10005;
const double EPS = 1e-5;
const int INF = INT_MAX;

bool cnt[MAX][2];

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY
     int n, m;
     while (cin >> n >> m) {
        set<int> numbers;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;

            numbers.insert(x);
        }

        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (!numbers.count(i)) {
                cout << i << ' ';
                ok = false;
            }
        }

        if (ok) {
            cout << '*';
        }

        cout << '\n';
     }

}
