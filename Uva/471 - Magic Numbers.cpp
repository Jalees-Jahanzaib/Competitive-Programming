#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF -1.0
#define ll long long
#define MOD 1000000007L

using namespace std;

long long n;

int main() {
    ios_base::sync_with_stdio(0);
    bool first = true;
    //unordered_set<long long> seen;
    vector<long long> all;
    queue<long long> q;
    for(int i = 1; i < 10; i++) q.push(i), q.push(1ll << i);
    while(!q.empty()) {
        long long u = q.front(); q.pop();
        long long used = q.front(); q.pop();
        //cout << u << endl;
        all.PB(u);

        if(__builtin_popcount(used) == 10) continue;

        for(int i = 0; i < 10; i++)
            if(!((1ll << i) & used) ) {
                q.push(u * 10ll + i);
                q.push(used | (1ll << i));
            }
    }
    int t;
    cin >> t;
    while(t--) {
        if(first) first = false;
        else cout << "\n";
        cin >> n;
        for(int i = 0; i < all.size(); i++) {
            ll k = n*all[i];
            if(k > 9876543210) break;
            int ok = 0;
            while(k > 0) {
                if((1 << (k % 10ll)) & ok) {
                    ok = 0;
                    break;
                }
                ok |= 1 << (k % 10ll);
                k /= 10ll;
            }

            if(ok) {
                cout << n * all[i] << " / " << all[i] << " = " << n << "\n";
            }
        }

    }

}


