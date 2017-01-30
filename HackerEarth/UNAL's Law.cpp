#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAX = 1010;

long long f(long long x) {
    return x + x*x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long y; cin >> y;
    long long high = 5ll*sqrt(y), low = 0;
    while(low <= high) {
        long long mid = (low + high) / 2ll;
        if(f(mid) <= y) low = mid+1ll;
        else high = mid-1ll;
    }

    cout << high << "\n";

}
