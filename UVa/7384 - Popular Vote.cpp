#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        int sum = 0, mx = -1, idx = -1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(mx < v[i]) {
                mx = v[i];
                idx = i;
            }
            sum += v[i];
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += mx == v[i];
        }

        if(cnt > 1) cout << "no winner\n";
        else {
            double res = (sum*1.0) / 2.0;
            if(double(mx) > res) cout << "majority winner " << 1+idx << "\n";
            else cout << "minority winner " << idx+1 << "\n";
        }

    }

}

