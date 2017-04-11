#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 3162280;
const double EPS = 1e-5;
const int INF = INT_MAX;

vector<ll> p;

void sieve() {
    vector<bool> prime(MAX, true);
    for(ll i = 2; i < MAX; i++) {
        if(prime[int(i)]) {
            p.push_back(i);
            for(ll j = i*i; j < MAX; j += i) {
                prime[int(j)] = false;
            }
        }
    }
}

void get_factors(ll n, vector<ll> &ans) {
    for(int i = 0; p[i]*p[i] <= n; i++) {
        if(n % p[i] == 0) {
            ans.push_back(p[i]);
            while(n % p[i] == 0) n /= p[i];
        }
    }
    if(n > 1) ans.push_back(n);
}

ll cnt_zeros(ll n, vector<ll> &f) {
    ll ans = 0;
    queue<ll> q;
    set<ll> seen;
    q.push(1);
    seen.insert(1);
    while(q.size()) {
        ll u = q.front(); q.pop();

        ll tmp = n;
        if(u != 1) {
//            cout << u << endl;
            while(tmp % u == 0) {
                tmp /= u;
                ++ans;
            }
        }

        for(int i = 0; i < f.size(); i++) {
            ll v = u*f[i];
            if(v <= n && n % v == 0 && !seen.count(v)) {
                seen.insert(v);
                q.push(v);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    sieve();

    ll n;
    while(cin >> n && n) {
        vector<ll> f;
        get_factors(n, f);
        cout << n << " " << cnt_zeros(n, f) << "\n";
    }

}
