#include <bits/stdc++.h>

#define PB push_back
#define ii pair< int, int >
#define state pair< int, ii >
#define MAX 100010
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

typedef long double lf;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int c, n;
    while(cin >> c >> n) {
        vector<int> acc(2*c);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            acc[x]++;
        }
        for(int i = 1; i < 2*c; i++) {
            acc[i] = acc[i-1] + acc[i];
        }
        int sz = c / n;
        bool ok = false;
        for(int i = 0; i < sz; i++) {
            bool tmp = true;
            for(int j = i + sz; j < c + i; j += sz) {
                if(acc[j - sz] + 1 != acc[j]) {
                    tmp = false;
                    break;
                }
            }
            if(tmp) {
                ok = true;
                break;
            }
        }
        if(ok) cout << "S\n";
        else cout << "N\n";

    }



}

