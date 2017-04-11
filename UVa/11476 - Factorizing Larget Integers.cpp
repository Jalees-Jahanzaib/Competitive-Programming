#include<bits/stdc++.h>
#include<time.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 40000;

ll mul(ll a, ll b, ll mod) {
    ll ret = 0;
    for (a %= mod, b %= mod;
         b != 0;
         b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)	ret -= mod;
        }
    }
    return ret;
}


ll fpow(ll a, ll b, ll MOD) {
    ll ans = 1ull;
    while(b > 0) {
        if(b&1) ans = mul(ans, a, MOD);
        a = mul(a, a, MOD);
        b >>= 1ull;
    }
    return ans;
}

const int rounds = 6;

bool miller_rabin(ll n) {
    if(n == 2 || n == 3) return true;
    if(n < 2 || (n&1) == 0) return false;
    for(int i = 0; i < rounds; i++) {
        int a = rand()%(n-4)+2;
        if(fpow(a, n-1, n) != 1)
            return false;
    }
    return true;
}

ll pollard_rho(ll n) {
  ll x, y, i = 1, k = 2, d;
  x = y = rand() % n;
  while (true) {
      ++i;
      x = mul(x, x, n);
      x += 2;
      if (x >= n) x -= n;
      if (x == y) return 1;
      d = __gcd((ll)abs(x - y), n);
      if (d != 1) return d;
      if (i == k) {
          y = x;
          k *= 2;
      }
  }
  return 1;
}

vector<ll> p;
void sieve() {
    vector<bool> prime(MAX+1, true);
    for(ll i = 2; i < MAX; i++) {
        if(prime[int(i)]) {
            p.push_back(i);
            for(ll j = i*i; j < MAX; j += i) {
                prime[int(j)] = false;
            }
        }
    }
}

void get_divisors(ll n, vector<ll> &ans) {
    if (n == 1) return;
    for (int i = 0; i < p.size() && p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            while (n % p[i] == 0) {
                n /= p[i];
                ans.push_back(p[i]);
            }
        }
    }
    if (n > 1) {
        ans.push_back(n);
    }
}

void factorize(ll n, vector<ll> &f) {
    if(n == 1) return;
    if(n < 1e9) {
        get_divisors(n, f);
        return ;
    }
    if (miller_rabin(n)) {
        f.push_back(n);
        return ;
    }

    ll d = n;
    while(d == 1 || d == n) {
        d = pollard_rho(n);
    }
    factorize(d, f);
    factorize(n/d, f);
}

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    srand(time(NULL));
    sieve();

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << n << " = ";

        vector<ll> ans;
        factorize(n, ans);

        map<ll, int> acc;
        for(auto &x : ans)
            acc[x]++;

        int c = 0;
        for(auto &x : acc) {
            if(c) cout << " * ";
            c++;
            cout << x.first;
            if(x.second != 1)
                cout << "^" << x.second;
        }
        cout << "\n";
    }
}
