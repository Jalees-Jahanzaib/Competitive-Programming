#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

typedef long long ll;

bool doit (ll p, int times, ll n) {
    ll ans = 1;
    for (int i = 0; i < times; ++i)
        ans *= p;
    return ans == n;
}

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    while(cin >> n && n != -1) {
        for (int i = 31; i >= 1; --i) {
            int p = pow(n, 1.0/double(i));

            if (doit(p - 1, i, n)) { cout << p - 1 << '^' << i << '\n'; break; }
            else if (doit(p, i, n)) { cout << p << '^' << i << '\n'; break; }
            else if (doit(p + 1, i, n)) { cout << p + 1 << '^' << i << '\n'; break; }
        }
    }

}

