#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


int main() {
    int t; cin >> t;

    while(t--) {
        int a;
        int n, m; cin >> n >> a >> m;

        set<ii> all;

        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            all.insert(ii(min(a, b), max(a,b)));
        }
        cout << int(all.size()) * 2 << "\n";


    }

}
