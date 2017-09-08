#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e5 + 10;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

int arr[MAX];

struct segtree{
    segtree *left, *right;
    int val;
    segtree(segtree *left, segtree *right, int val) {
        this->left = left;
        this->right = right;
        this->val = val;
    }
    segtree() : left(this), right(this), val(0) {
    }

    segtree* update(int pos, int start, int end) {
        if(start == end)
            return new segtree(NULL, NULL, val+1);
        int mid = (start+end)/2;
        if(pos <= mid)
            return new segtree( left->update(pos, start, mid), right, val+1);
        return new segtree( left, right->update(pos, mid+1, end), val+1);
    }
};

int query(segtree *a, segtree *b, int k, int start, int end) {
    if(start == end) {
        return start;
    }

    int cnt = b->left->val - a->left->val;
    int mid = (start+end)/2;
    if(cnt >= k) {
        return query(a->left, b->left, k, start, mid);
    }
    return query(a->right, b->right, k - cnt, mid+1, end);
}

segtree *root[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> c = v;
    sort(c.begin(), c.end());
    for(int i = 0; i < n; i++) {
        v[i] = lower_bound(c.begin(), c.end(), v[i]) - c.begin();
    }

    root[0] = new segtree();
    for(int i = 1; i <= n; i++) {
        root[i] = root[i-1]->update(v[i-1], 0, n-1);
    }
    while(m--) {
        int a, b, k; cin >> a >> b >> k;
        cout << c[query(root[a-1], root[b], k, 0, n-1)] << "\n";
    }


}
