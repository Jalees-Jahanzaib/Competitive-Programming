#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 200;
const double EPS = 1e-5;
const int INF = INT_MAX/2;
const ll MOD = 1000000007;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

const int consuption[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
     ios_base::sync_with_stdio(0);
//     cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0, con = 100000;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            assert(x >= 0);
            int cnt = 0, tmp = x;
            if(x == 0) cnt = consuption[x];
            while(x) {
                cnt += consuption[x%10];
                x /= 10;
            }
            if(con > cnt) {
                ans = tmp;
                con = cnt;
            }
        }

        cout << ans << "\n";
    }

}
