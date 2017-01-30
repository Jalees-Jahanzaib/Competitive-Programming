#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int MOD = 1000000007;
const int MAX = 1010;

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<ll> all(n);
        for(int i = 0; i < n; i++) cin >> all[i];
        ll total = 0;
        for(int i = n-1; i >= 0; i--) {
            total += all[i];
            for(int j = 0; j < i; j++)
                all[j] += all[i];
        }
        cout << total << "\n";
    }



}
