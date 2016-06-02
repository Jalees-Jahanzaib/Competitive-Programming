#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e2 * 5 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int n;
ll r;
vector<int> f;
vector< vector<int> > mod;

void solve(int cur, int init) {
    if(init == cur) return;
    //cout << cur << endl;
    mod[init].PB(cur);
    solve(f[cur], init);
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n >> r) {
        f.resize(n + 1);
        for(int i = 1; i <= n; i++) cin >> f[i];

        mod = vector<vector<int> > (n + 1);
        for(int i = 1; i <= n; i++) {
            //cout << i << endl;
            mod[i].PB(i);
            solve(f[i], i);
            if(i != 1) cout << " ";
            cout << mod[i][r % (ll)mod[i].size()];
        }
        cout << "\n";
    }
}



