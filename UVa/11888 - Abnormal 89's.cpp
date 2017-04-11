#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 3000000;
const double EPS = 1e-5;
const int INF = INT_MAX;

#define NMODS           2
int mods[] = {999999929, 1000000007}; //999999937, 1000000009
#define form            for (int m = 0; m < NMODS; ++m)
#define mod             mods[m]
#define x               X[m]
#define op              inline mint operator
#define arg             (const mint &a) const
struct mint {
    int X[NMODS];
    op + arg { mint r; form r.x = (x + a.x) % mod; return r; }
    op - arg { mint r; form r.x = (x - a.x + mod) % mod; return r; }
    op * arg { mint r; form r.x = (ll(x) * ll(a.x)) % mod; return r; }
    //op / arg { return (*this) * a.inv(); }
    inline bool operator < arg { form if (x != a.x) return x < a.x; return 0; }
    inline bool operator == arg { form if (x != a.x) return 0; return 1; }
    inline mint &operator = (const mint &a) { form x = a.x; return *this; }
    //inline mint inv() const { mint r; form r.x = fpow(x,mod-2,mod); return r;}
    mint (int v) { form x = v; }
    mint () { form x = 0; }
};
#undef x
#undef form

struct hashcode {
    vector<mint> code, p;
    mint base;
    int n;
    hashcode (string &s) : n(s.size()), base(256) {
        p.resize(n + 1); code.resize(n + 1);
        p[0] = 1;
        code[0] = s[0];
        for ( int i = 1; i < n; ++i ) {
            p[i] = base * p[i - 1];
            code[i] = code[i - 1] + (mint(s[i]) * p[i]);
        }
        p[n] = base * p[n - 1];
    }
    mint query (int l, int r) {
        return (code[r] - (l ? code[l - 1] : mint(0))) * p[n-l];
    }
};

int compute(hashcode &a, hashcode &b) {
    for(int i = 0, j = b.n-1; i < a.n-1; i++, j--) {
        if(a.query(0, i) == b.query(j, b.n-1) && a.query(i+1, a.n-1) == b.query(0, j-1))
            return 1;
    }
    if(a.query(0, a.n-1) == b.query(0, a.n-1)) return 2;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        string a; cin >> a;
        string b = a;
        reverse(b.begin(), b.end());

        hashcode hasha(a), hashb(b);
        int res = compute(hasha, hashb);
        if(res == 1) cout << "alindrome\n";
        else if(res == 2) cout << "palindrome\n";
        else cout << "simple\n";
    }
}
