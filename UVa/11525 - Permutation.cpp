#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 50010
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int bit[MAX];

void update(int x, int val) {
    for(; x < MAX; x += x&-x)
        bit[x] += val;
}

int get(int x) {
    int ans = 0;
    for(; x > 0; x -= x&-x)
        ans += bit[x];
    return ans;
}

int n;

int findG(int cumFre){
    int idx = 0, bitMask = 1<<(31 - __builtin_clz(n));

    while ((bitMask != 0) && (idx < MAX)) {
        int tIdx = idx + bitMask;
        if (tIdx < MAX && cumFre >= bit[tIdx]){
            idx = tIdx;
            cumFre -= bit[tIdx];
        }
        bitMask >>= 1;
    }
    if (cumFre != 0)
        return -1;
    else
        return idx;
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        memset(bit, 0 , sizeof bit);
        update(n+1, 1);
        for(int i = 1; i <= n; i++)
            update(i, 1);

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x++;
            int ans = findG(x);
            if(i) cout << " ";
            cout << ans;
            update(ans+1, -1);
        }

        cout << "\n";
    }


}
