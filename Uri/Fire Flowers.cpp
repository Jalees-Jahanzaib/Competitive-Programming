#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 400000;
const ll MOD = 1e9 + 7;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll r1, x1, x2, y1, y2, r2;
    while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
        ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        if( dist <= (r1-r2)*(r1-r2) && r1 >= r2) {
            cout << "RICO\n";
        } else {
            cout << "MORTO\n";
        }
    }

}
