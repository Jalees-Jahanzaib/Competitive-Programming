#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF -1.0
#define ll long long
#define MOD 1000000007L

using namespace std;

int kmp(string p, string t) {
    int ans = 0;

    phi[0] = k = -1;
    for(int i = 1; i <= p.size(); i++) {
        while( k > -1 && p[k] != p[i-1]) k = phi[k];
        phi[i] = ++k;
    }

    k = 0;
    for(int i = 0; i < t.size(); i++) {
        while(k > -1 && p[k] != t[i]) return k;
        ++k;
    }
    return k;

}

int t;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
    }


}


