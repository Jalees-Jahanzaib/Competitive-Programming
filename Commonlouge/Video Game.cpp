#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 50010;
const double EPS = 1e-5;
const int INF = INT_MAX/4;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n, h; cin >> n >> h;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    int q;
    int pos = 0, has = 0;
    while(cin >> q && q) {
//        cout << "command = " << q << endl;
        if(q == 1) {
            pos = max(0, pos-1);
        }
        if(q == 2) {
            pos = min(n-1, pos+1);
        }
        if(q == 3) {
            if(has) continue;
            if(ans[pos] > 0) ans[pos]--, has++;
        }
        if(q == 4) {
            if(!has) continue;
            if(ans[pos] < h) {
                ans[pos]++; has--;
//                cout << "en pos ahi " << ans[pos] << " < " << h << endl;
            }
        }
//        cout << "pos = " << pos << " has " << has << endl;
//        for(int i = 0; i < n; i++) {
//            if(i) cout << " ";
//            cout << ans[i];
//        }
//        cout << endl << endl;
    }

    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
