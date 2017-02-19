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

int cases;

int good[] = {1, 2, 3, 3, 4, 10};
int bad[] = {1, 2, 2, 2, 3, 5, 10};

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int a = 0, b = 0;
        for(int i = 0; i < 6; i++) {
            int x; cin >> x;
            a += x*good[i];
        }
        for(int i = 0; i < 7; i++) {
            int x; cin >> x;
            b += x*bad[i];
        }

        cout << "Battle " << ++cases << ": ";
        if(a > b) cout << "Good triumphs over Evil\n";
        else if(a < b) cout << "Evil eradicates all trace of Good\n";
        else cout << "No victor on this battle field\n";
    }

}
