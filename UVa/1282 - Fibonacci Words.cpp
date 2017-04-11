#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 200005;
const double EPS = 1e-5;
const int INF = INT_MAX;

int phi[MAX];

void pre(string &p) {
    phi[0] = -1;
    for (int i = 0, j = -1; i < p.size();) {
        while( j > -1 && p[j] != p[i]) j = phi[j];
        i++; j++;
        phi[i] = j;
    }
}

ll KMP (string &p, string &t) {
    ll matches = 0;
    for(int i = 0, j = 0; i < t.size();) {
        while(j > -1 && p[j] != t[i]) j = phi[j];
        i++; j++;
        if(j == p.size()) matches++, j = phi[j];
    }
    return matches;
}

string get_suff(string &x, int n) {
    return x.substr(x.size() - n);
}

string get_pref(string &x, int n) {
    return x.substr(0, n);
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    int n;
    while(cin >> n) {
        string p; cin >> p;
        pre(p);

        string a = "0", b = "1";
        int i = 2;
        for(; i <= n; i++) {
            string c = b+a;
            a = b; b = c;
            if(a.size() >= p.size()) {
                i++;
                break;
            }
        }

        if(n == 0) b = a;
        if(i > n) {
             cout << "Case " << ++cases << ": " << KMP(p, b) << "\n";
        } else {

            int k = p.size();
            string pref_a = get_pref(a, k-1);
            string pref_b = get_pref(b, k-1);
            string suff_a = get_suff(a, k-1);
            string suff_b = get_suff(b, k-1);

            ll times_a = KMP(p, a), times_b = KMP(p, b);

            for(; i <= n; i++) {
                string c = suff_b + pref_a;
                ll times_c = KMP(p, c) + times_b + times_a;
                string pref_c = pref_b;
                string suff_c = suff_a;
                times_a = times_b; pref_a = pref_b; suff_a = suff_b;
                times_b = times_c; pref_b = pref_c; suff_b = suff_c;
            }
            cout << "Case " << ++cases << ": " << times_b << "\n";
        }
    }
}
