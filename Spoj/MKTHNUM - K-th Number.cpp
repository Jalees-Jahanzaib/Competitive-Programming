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
    int start, end, val;
    segtree(segtree *left, segtree *right, int start, int end, int val) {
        this->left = left;
        this->right = right;
        this->val = val;
        this->start = start;
        this->end = end;
    }
    segtree(int start, int end) : start(start), end(end) {
        if(start == end) {
            val = 0;
            left = right = NULL;
        } else {
            int mid = (start+end)/2;
            left = new segtree(start, mid);
            right = new segtree(mid+1, end);
            val = left->val + right->val;
        }
    }

    segtree* update(int pos) {
        if(start == end)
            return new segtree(NULL, NULL, start, end, val+1);
        int mid = (start+end)/2;
        if(pos <= mid)
            return new segtree( left->update(pos), right, start, end, val+1);
        return new segtree( left, right->update(pos), start, end, val+1);
    }
};

int query(segtree *a, segtree *b, int k) {
    if(a->start == a->end) {
        return a->start;
    }

    int cnt = b->left->val - a->left->val;
    if(cnt >= k) { /// izquierda
        return query(a->left, b->left, k);
    }
    return query(a->right, b->right, k - cnt);
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

    root[0] = new segtree(0, n-1);
    for(int i = 1; i <= n; i++) {
        root[i] = root[i-1]->update(v[i-1]);
    }

    while(m--) {
        int a, b, k; cin >> a >> b >> k;
        cout << c[query(root[a-1], root[b], k)] << "\n";


    }


}
