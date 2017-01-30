#include<bits/stdc++.h>

using namespace std;

#define z first
#define x second.first
#define y second.second

typedef double ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 100010;

int arr[MAX];

void update(int xx, int val) {
    for(; xx < MAX; xx += -xx&xx)
        arr[xx] = min(arr[xx], val);
}

int rmq(int xx) {
    int ans = INF;
    for(; xx > 0; xx -= -xx&xx)
        ans = min(arr[xx], ans);
    return ans;
}

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<iii> all(n);
        for(int i = 0; i < n; i++) {
            cin >> all[i].z >> all[i].x >> all[i].y;
        }
        sort(all.begin(), all.end());

        fill(arr, arr+n+3, INF);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int mn = rmq(all[i].x);
            if(all[i].y < mn) {
                ans++;
            }
            update(all[i].x, all[i].y);
        }

        cout << ans << "\n";
    }

}

