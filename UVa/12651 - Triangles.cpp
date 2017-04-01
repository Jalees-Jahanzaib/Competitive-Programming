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

     int n;
     while(cin >> n) {
        int len = 0;
        vector<int> v(2*n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            v[i+n] = v[i];
            len += v[i];
        }
        int ans = 0;
        if(len % 3 == 0) {
            vector<int> acc(2*n);
            acc[0] = v[0];
            for(int i = 1; i < 2*n; i++) {
                acc[i] = acc[i-1]+v[i];
            }
            len /= 3;
            for(int i = 0; i < n; i++) {
                if(binary_search(acc.begin(), acc.end(), acc[i]+len) &&
                   binary_search(acc.begin(), acc.end(), acc[i]+2*len))
                    ans++;
            }
        }

        cout << ans/3 << "\n";
     }


}
