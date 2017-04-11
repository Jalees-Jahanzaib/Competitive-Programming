#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 10001;
const double EPS = 1e-5;
const int INF = INT_MAX;

ll phi[MAX];
ll ret[MAX];

void sieve() {
    vector<bool> prime(MAX, true);
    prime[1] = false;

    for (int i = 2; i < MAX; i++)
        if (prime[i])
            for (int j = i*i; j < MAX; j += i)
                prime[j] = false;

    for (int i = 1; i < MAX; i++)
        phi[i] = i;

    for (int i = 1; i < MAX; i++)
        if (prime[i]) // is prime
            for (int j = i; j < MAX; j += i)
                phi[j] -= phi[j] / i;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    sieve();
    ll sum_phi = 0;
    for(int i = 1; i < MAX; i++) {
        ret[i] = sum_phi*phi[i];
        sum_phi += phi[i];
        ret[i] += sum_phi*phi[i] + ret[i-1];
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << ret[n] << "\n";
    }
}
