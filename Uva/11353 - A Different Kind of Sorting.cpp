#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 2000000 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int divisors[MAX + 10];
vector<ii> all;

void precalc() {
    for(int i = 2; i <= MAX; i++) {
        if(divisors[i] == 0) {
            for(int j = i; j <= MAX; j += i) {
                int tmp = j;
                while(tmp % i == 0) {
                    divisors[j]++;
                    tmp /= i;
                }
            }
        }
    }

    for(int i = 1; i <= 2000000; i++) {
        //cout << i << " - " << divisors[i] << endl;
        all.PB(ii(divisors[i], i));
    }

    sort(all.begin(), all.end());

}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    precalc();
    int n;
    while(cin >> n && n != 0) {
        cout << "Case " << ++cases << ": " << all[n - 1].second << "\n";
    }





}
