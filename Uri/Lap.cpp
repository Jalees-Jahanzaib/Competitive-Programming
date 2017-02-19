#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 10000;
const int limit = 4e8;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int main( ) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll n, m; cin >> n >> m;
    int ans = 1;
    ll a = n, b = m;
    while(true) {
        a += n; b += m;
        ans++;
        if(b-a >= m) {
            cout << ans << "\n";
            return 0;
        }
    }

}
