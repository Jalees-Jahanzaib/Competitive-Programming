#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;

bool is_prime[MAX];
int divisors[MAX];

void sieve(int n) {
    memset(is_prime, true, sizeof is_prime);

    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) continue;
        divisors[i]++;
        for(int j = i+i; j <= n; j += i) {
            is_prime[j] = false;
            int times = 0, tmp = j;
            while(tmp % i == 0) {
                times++;
                tmp /= i;
            }

            divisors[j] += divisors[j]*times + times;

        }
    }
    for(int i = 0; i <= n; i++) divisors[i]++;
}

int main() {
//    freopen("testgen.in", "r", stdin);
//    freopen("testgen.out", "w", stdout);


    int n; cin >> n;
    sieve(n);
    int cnt = 0, maximal = -1;
    for(int i = 2; i <= n; i++) {
        int d = divisors[i];
        if(maximal < d ) {
            maximal = d;
            cnt = n - i + 1;
        }
    }

    cout << cnt << "\n";



}
