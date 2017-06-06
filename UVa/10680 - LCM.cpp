#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 1000010;
const int INF = INT_MAX/3;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

int acc[MAX];
int ans[MAX];
int cnt2 = 0, cnt5 = 0;

void update(int p, int times, int &lcm) {
    if(p == 2)
        cnt2 = max(cnt2, times);
    else if(p == 5)
        cnt5 = max(cnt5, times);
    else if(times > acc[p]) {
        for(int j = acc[p]+1; j <= times; j++) {
            lcm = (lcm*p)%10;
        }
        acc[p] = times;
    }
}

void factorize(int n, int &lcm) {
    for(int p = 2; p*p <= n; p++) {
        if(n % p == 0) {
            int times = 0;
            while(n % p == 0) {
                n /= p;
                times++;
            }
            update(p, times, lcm);

        }
    }
    if(n > 1) {
        update(n, 1, lcm);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    int lcm = 1; ans[1] = 1;
    cnt2 = cnt5 = 0;
    for(int i = 2; i <= 1000000; i++) {
        factorize(i, lcm);
        ll tmp = lcm;
        for(int j = 0; j < cnt2 - cnt5; j++) {
            tmp = (tmp * 2) % 10;
        }
        ans[i] = tmp % 10;
    }

    int n;
    while(cin >> n && n) {
        cout << ans[n] << "\n";
    }



}
