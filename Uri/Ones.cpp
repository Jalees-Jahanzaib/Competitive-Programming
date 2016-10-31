#include<bits/stdc++.h>

#define MOD			10000000
#define MAX_N		100000

using namespace std;

typedef long long ll;

const int MAX = 100010;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n) {
        int cur = 1;
        int ans = 1;
        while(cur) {
            cur = (cur*10 + 1) % n;
            ans++;
        }
        cout << ans << "\n";

    }

}
