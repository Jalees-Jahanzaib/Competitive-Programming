#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("prepare.in", "r", stdin);
    freopen("prepare.out", "w", stdout);

    int n; scanf("%d", &n);
    vector<int> t(n), p(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    int ans = 0, best = 100000000, idx = -1;
    bool theorical = false, practical = false;
    vector<int> diff(n);
    for(int i = 0; i < n; i++) {
        if(t[i] >= p[i]) {
            theorical = true;
            ans += t[i];
        }
        else {
            practical = true;
            ans += p[i];
        }
        diff[i] = abs(t[i] - p[i]);
        if(diff[i] < best) {
            best = diff[i];
            idx = i;
        }
    }

    if(!theorical) {
        ans = (ans - p[idx]) + t[idx];
    }
    else if(!practical) {
        ans = (ans - t[idx]) + p[idx];
    }

    printf("%d\n", ans);

}
