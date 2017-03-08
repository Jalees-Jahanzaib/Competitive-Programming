#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 100010;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

int main( ) {
    double h, u, d, f;
    while(cin >> h >> u >> d >> f && (h+u+d+f != 0)) {
        int cur_day = 0;
        double pos = 0.0, low = u*(f/100.0);
        do {
            cur_day++;
            pos += u;
            if(pos > h) break;
            u -= low;
            u = max(0.0, u);
            pos -= d;
        } while(pos >= 0.0);
        if(pos <= 0.0) cout << "failure on day " << cur_day << "\n";
        else cout << "success on day " << cur_day << "\n";
    }

}
