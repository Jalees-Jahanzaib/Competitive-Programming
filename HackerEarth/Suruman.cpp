#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 300010;
const ll MOD = 1e9 + 7;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

ll dp[64][2][64];
ll n;

ll go(int pos, bool lower, int ones) {
    if(pos == -1) {
        if(ones%3 == 0 && ones != 0) {
            return 1;
        }
        else return 0;
    }
    ll &r = dp[pos][lower][ones];
    if(r == -1) {
        r = 0;
        if(!lower) {
            if( (n>>pos)&1 )
                r += go(pos-1, false, ones+1);
            r += go(pos-1, (n>>pos)&1, ones);
        } else {
            r += go(pos-1, true, ones);
            r += go(pos-1, true, ones+1);
        }
    }
    return r;
}

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    while(cin >> n) {
        memset(dp, -1, sizeof dp);
        cout << "Day " << n << ": Level = " << go(62, false, 0) << "\n";
    }

}
