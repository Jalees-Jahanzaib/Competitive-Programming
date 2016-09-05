#include <bits/stdc++.h>

#define PB push_back
#define ii pair< int, int >
#define state pair< int, ii >
#define MAX 510
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

struct plane {
    int A, B, C, D;
    plane() {}
};

unordered_map<bitset<MAX>, int> all;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n, m;
    while(cin >> m >> n) {
        all.clear();
        vector<plane> planes(m);
        vector<int> ans(m);
        for(int i = 0; i < m; i++) cin >> planes[i].A >> planes[i].B >> planes[i].C >> planes[i].D;
        int best = 0;
        for(int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            bitset<MAX> tmp;
            for(int j = 0; j < m; j++) {
                if( planes[j].A*x + planes[j].B*y + planes[j].C*z < planes[j].D)
                    tmp[j] = 1;
            }
            all[tmp]++;
            best = max(best, all[tmp]);
        }

        cout << best << "\n";

    }

}

