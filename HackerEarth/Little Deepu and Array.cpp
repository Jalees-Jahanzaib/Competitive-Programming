#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 200;
const double EPS = 1e-5;
const int INF = INT_MAX/2;
const ll MOD = 1000000007;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

const int consuption[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

template <class type>
struct bit {
    vector<type> tree;
    int n;
    bit (int n) : n(n), tree(vector<type>(n + 1)) {}
    type query (int x) {
        type sum = 0;
        for (; x; x -= -x & x) sum += tree[x];
        return sum;
    }
    void update (int x, type val) {
        for (; x <= n; x += -x & x) tree[x] += val;
    }
    type query (int l, int r) {
        return query(r) - query(l - 1);
    }
    void update (int l, int r, type val) {
        update(l, val); update(r + 1, -val);
    }
};

int main() {
     ios_base::sync_with_stdio(0);
//     cin.tie(0);

    int n; cin >> n;
    vector<ii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    bit<ll> b(n);

    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        int low = 1, high = n;
        while(low <= high) {
            int mid = (low+high)/2;
            ll p = v[mid-1].first-b.query(mid);
            if(p <= x) low = mid+1;
            else high = mid-1;
        }
        b.update(low, n, 1);
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[ v[i].second ] = v[i].first-b.query(i+1);
    }

    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

}
