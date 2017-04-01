#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

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
    inline bool operator < arg { form if (x != a.x) return x < a.x; return 0; }
    inline bool operator == arg { form if (x != a.x) return 0; return 1; }
    inline mint &operator = (const mint &a) { form x = a.x; return *this; }

    mint (int v) { form x = v; }
    mint () { form x = 0; }
};
#undef x
#undef form

template <class container>
struct hashcode {
    vector<mint> code, p;
    mint base;
    int n;
    hashcode (container &s) : n(s.size()), base(256) {
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

vector<int> to;
mint destination;
map<mint, int> cache;

void fold (vector<int> &v, vector<int> &result, int idx) {
    deque<int> st;
    int n = v.size();
    int l = idx, r = idx + 1;
    int a, b;
    for (; l >= 0 || r < n; ++r, --l) {
        a = b = 0;
        if (l >= 0) a = v[l];
        if (r < n) b = v[r];
        st.push_front(a + b);
    }
    result = vector<int>(st.begin(), st.end());
}

int go (vector<int> &state) {
    hashcode<vector<int>> tmp(state);
    mint code = tmp.query(0, state.size() - 1);

    if (code == destination) return cache[code] = true;
    if (cache.count(code)) return cache[code];

    int n = state.size();

    int &r = cache[code];
    r = false;
    for (int i = -1; i < n - 1; ++i) {
        vector<int> result;
        fold(state, result, i);

        if (result.size() < to.size())
            continue;

        if (go(result))
            return r = true;
    }

    return r;
}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

     int n, m;

     while (cin >> n) {
        cache.clear();

        vector<int> from(n);
        for (int i = 0; i < n; ++i) {
            cin >> from[i];
        }

        cin >> m;
        to = vector<int>(m);
        for (int i = 0; i < m; ++i) {
            cin >> to[i];
        }

        hashcode<vector<int>> to_code(to);
        destination = to_code.query(0, m - 1);

        cout << (go(from) ? "S" : "N") << '\n';
     }


}
