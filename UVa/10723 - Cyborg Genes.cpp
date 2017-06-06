#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 40;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

int dp1[MAX][MAX], dp2[MAX][MAX][2*MAX];
string a, b;

int go1(int ida, int idb) {
    if(ida == a.size() && idb == b.size()) return dp1[ida][idb] = 0;
    int &r = dp1[ida][idb];
    if(r == -1) {
        r = INT_MAX/2;
        if(ida < a.size()) r = min(r, 1 + go1(ida+1, idb));
        if(idb < b.size()) r = min(r, 1 + go1(ida, idb+1));
        if(ida < a.size() && idb < b.size() && a[ida] == b[idb])
            r = min(r, 1 + go1(ida+1, idb+1));
    }
    return r;
}

int go2(int ida, int idb, int len) {
    if(len == 0) {
        if(ida == a.size() && idb == b.size()) return 1;
        return 0;
    }
    int &r = dp2[ida][idb][len];
    if(r == -1) {
        r = 0;
        if(ida < a.size() && idb < b.size() && a[ida] == b[idb]) r += go2(ida+1, idb+1, len-1);
        else {
            if(dp1[ida+1][idb] == len-1) r += go2(ida+1, idb, len-1);
            if(dp1[ida][idb+1] == len-1) r += go2(ida, idb+1, len-1);
        }
    }
    return r;
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    cin.ignore();
    while(t--) {
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);

        getline(cin, a);
        getline(cin, b);

        int len = go1(0, 0);
        cout << "Case #" << ++cases << ": " << len << " " << go2(0, 0, len) << "\n";
    }


}
