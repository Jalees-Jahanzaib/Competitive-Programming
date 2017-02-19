#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t; cin >> t;
    while(t--) {
        bool ok = true;
        vector<int> all(5);
        for(int i = 0; i < 5; i++) {
            cin >> all[i];
            if(i)
                ok &= all[i]-1 == all[i-1];
        }
        if(ok) cout << "Y\n";
        else cout << "N\n";
    }
}
