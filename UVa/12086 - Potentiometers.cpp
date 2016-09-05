    #include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 200010
#define INF 0x3fffffff
#define ll long long
#define MOD 1000000007

using namespace std;

int tree[4*MAX];
int n;

void update(int x, int val, int idx = 1, int l = 1, int r = n) {
    if(l == r) {tree[idx] = val; return; }
    int mid = (l+r)/2;
    if(x <= mid) update(x, val, 2*idx, l, mid);
    else update(x, val, 2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

int query(int s, int e, int idx = 1, int l = 1, int r = n) {
    //cout << s << " " << e << " " << idx << " " << l << " " << r << endl;
    if(s == l && e == r) return tree[idx];
    int mid = (l+r)/2;
    if(e <= mid) return query(s, e, 2*idx, l, mid);
    else if( s > mid) return query(s, e, 2*idx+1, mid+1, r);
    else return query(s, mid, 2*idx, l, mid) + query(mid+1, e, 2*idx+1, mid+1, r);
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool first = true;
    int *r = tree;
    cout << sizeof(r) << endl;
    while(cin >> n && n != 0) {
        if(!first) cout << "\n";
        first = false;
        int val;
        for(int i = 0; i < n; i++) {
            cin >> val;
            update(i+1, val);
        }
        /*for(int i = 0; i < 4*n; i++) {
            cout << tree[i] << " ";
        }*/
        string cmd;
        cout << "Case " << ++cases << ":\n";
        while(cin >> cmd && cmd != "END") {
            int a, b;
            cin >> a >> b;
            if(cmd == "M") cout << query(a, b) << "\n";
            else update(a, b);
        }
    }
}
