#include<bits/stdc++.h>

using namespace std;

int phi[100000];

int KMP (string &p, string &t) {
    if(p.size() > t.size()) return 0;
    int matches = 0;
    phi[0] = -1;

    for (int i = 0, j = -1; i < p.size();) {
        while( j > -1 && p[j] != p[i]) j = phi[j];
        i++; j++;
        phi[i] = j;
    }

    for(int i = 0, j = 0; i < t.size();) {
        while(j > -1 && p[j] != t[i]) j = phi[j];
        i++; j++;
        if(j == p.size()) matches++, j = phi[j];
    }
    return matches;
}

int main( ) {
//    ios_base::sync_with_stdio( 0 );
//    cin.tie( 0 );

    int n;

    while( cin >> n ) {
        int ans = -1;
        for(int i = 1; i <= 100000; i++) {
            for(int j = 1; j <= i; j++) {
                ans = max(ans, min(j, 1000000/i) );
            }
        }

        cout << ans << endl;
    }

  return 0;
}
