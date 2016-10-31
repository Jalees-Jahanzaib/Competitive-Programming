#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    for(int i = 0; i <= 20; i++) {
        if(n - 7ll*i >= 0 && (n - 7ll*i)%20 == 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
