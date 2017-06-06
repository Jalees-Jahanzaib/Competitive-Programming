#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 100010;
const int INF = INT_MAX/3;

ll bit[MAX];

void update(int x, ll val) {
    for( ; x < MAX; x += -x&x) {
        bit[x] += val;
    }
}

ll get(ll x) {
    ll ans = 0;
    for( ; x > 0; x -= -x&x) {
        ans += bit[x];
    }
    return ans;
}

int r[MAX], t[MAX];
ll ans[MAX];
vector<vector<int>> G;

void go(int u) {

    update(r[u], t[u]);
    ll pre = get(r[u]-1);

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        go(v);
    }

    ans[u] = get(r[u]-1) - pre;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    int n;
    while(cin >> n) {
        memset(bit, 0, sizeof bit);
        G = vector< vector<int> > (n+1);
        int root = -1;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x >> r[i] >> t[i];
            if(x == -1) root = i;
            else G[x].push_back(i);
        }

        go(root);

        for(int i = 1; i <= n; i++) {
            cout << ans[i] << "\n";
        }
    }


}
