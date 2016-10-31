#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = INT_MAX;
const int MAX = 1010;

const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        vector<int> all(3);
        int taco; cin >> taco >> all[0] >> all[1] >> all[2];
        sort(all.begin(), all.end());
        if(all[0] + all[1] <= all[2]) {
            cout << min(taco, all[0] + all[1]) << "\n";
        }
        else {
            int ans = taco;
            int mid1 = all[0] / 2;
            int mid2 = (all[0] + 1) / 2;
            if(mid1 > mid2) swap(mid1, mid2);
            cout << max( 0, min(taco, all[0] + min(all[2] - mid2, all[1] - mid1) ) )<< "\n";
        }
    }

}
