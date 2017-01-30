#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1000010;

int cnt[MAX];

int main() {
    freopen("stacks.in", "r", stdin);
    freopen("stacks.out", "w", stdout);

    int n; scanf("%d", &n);
    int cur = 0, ans = 1;
    cnt[cur] = 1;
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if(x == 0) {
            cnt[cur+1]++; cnt[cur]--;
            ans = max(ans, cur+1);
        } else {
            cur = 1;
            cnt[cur]++;
        }

        if(cnt[cur] == 0) cur++;
    }

    printf("%d\n", ans);


    return 0;

}
