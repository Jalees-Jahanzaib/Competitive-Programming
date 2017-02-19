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

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    while(cin >> n && n) {
        vector<int> v(n);
        vector<bool> seen(100);
        bool ok = true;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        string ans(20, '-');
        int p = 0;
        char c = 'A';
        for(int i = 0; i < 20; i++, p = (p+1)%n) {
            if(ans[i] == '-') {
                ans[i] = c++;
            }
            if(i+v[p] >= 20) continue;
            if(ans[i+v[p]] != '-') ok = false;
            ans[i+v[p]] = ans[i];
        }

        if(ok) cout << ans << "\n";
        else cout << "CRASH\n";

    }
}
