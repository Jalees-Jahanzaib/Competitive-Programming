//#include<bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

#define id1 second.first
#define id2 second.second
#define val first

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 55;
const double EPS = 1e-5;
const int INF = INT_MAX/2;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int n;

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // LOCAL

    while(cin >> n && n) {
        vector<ll> nums(n);
        vector<iii> v;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            for(int j = 0; j < i; j++) {
                v.push_back(iii(nums[i]+nums[j], ii(i, j)));
            }
        }

        sort(v.begin(), v.end());
        vector<ll> x(v.size());
        for(int i = 0; i < v.size(); i++) {
            x[i] = v[i].val;

        ll ans = -LLONG_MAX, o;
        for(int d = 0; d  < n; d++) {
            for(int c = 0; c < n; c++) {
                if(c == d) continue;
                int pos = lower_bound(x.begin(), x.end(), nums[d]-nums[c]) - x.begin();

                while(pos < x.size() && (v[pos].id1 == d || v[pos].id2 == d || v[pos].id1 == c || v[pos].id2 == c) &&
                      v[pos].val == nums[d]-nums[c]) {
                    pos++;
                }
                if(pos == n) continue;
                if(v[pos].val != nums[d]-nums[c]) continue;
                ans = max(ans, nums[d]);
            }
        }

        if(ans == -LLONG_MAX) {
            cout << "no solution\n";
        } else {
            cout << ans << "\n";
        }

    }
}
