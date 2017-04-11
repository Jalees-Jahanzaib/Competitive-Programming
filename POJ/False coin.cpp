//#include <bits/stdc++.h>
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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 1010;
const double EPS = 1e-5;
const int INF = INT_MAX;

bool can[MAX];
int cnt[MAX][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    for(int i = 0; i < MAX; i++) can[i] = true;

    int n, k; cin >> n >> k;
    int total = k;
    while(k--) {
        int x; cin >> x;
        vector<int> a(x);
        for(int i = 0; i < x; i++) {
            cin >> a[i];
        }
        vector<int> b(x);
        for(int i = 0; i < x; i++) {
            cin >> b[i];
        }
        char c; cin >> c;

        for(int i = 0; i < a.size(); i++) {
            if(c == '<') cnt[ a[i] ][0]++;
            if(c == '>') cnt[ a[i] ][1]++;
        }
        for(int i = 0; i < b.size(); i++) {
            if(c == '<') cnt[ b[i] ][1]++;
            if(c == '>') cnt[ b[i] ][0]++;
        }

        if(c == '=') {
            total--;
            for(int i = 0; i < a.size(); i++)
                can[ a[i] ] = false;
            for(int i = 0; i < b.size(); i++)
                can[ b[i] ] = false;
        }

    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(can[i] && (cnt[i][0] == total || cnt[i][1] == total)) ans.push_back(i);
    }

    if(ans.size() != 1) cout << 0 << "\n";
    else cout << ans[0] << "\n";


}
