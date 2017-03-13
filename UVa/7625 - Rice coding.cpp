#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q(int i, int k) {
    return i/(1<<k);
}

int L(int i, int k) {
    return q(i, k)+1+k;
}

int U(int i) {
    if (i < 0) return -2*i-1;
    return 2*i;
}

int M(int i, int k) {
    if (q(U(i), k) < 8)
        return L(U(i), k);
    return 25;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != -1) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mn = INT_MAX;
        for(int k = 0; k <= 14; k++) {
            int sum = 0;
            for(int i = 0; i < n; i++) sum += M(a[i],k);
            mn = min(mn, sum);
        }
        cout << mn << "\n";
    }

}

