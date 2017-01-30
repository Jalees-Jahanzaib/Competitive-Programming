#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, int> ii;

const int MAX = 1010;

string ADN = "AGCT";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        queue<string> q1;
        queue<int> q2;
        q1.push(s);
        q2.push(0);
        set<ii> seen;
        seen.insert(ii(s, 0));
        set<string> ans;
        while(!q1.empty()) {
            string u = q1.front(); q1.pop();
            int mask = q2.front(); q2.pop();

            ans.insert(u);

            if(__builtin_popcount(mask) == k) continue;

            for(int i = 0; i < u.size(); i++) {
                if(!((mask>>i)&1)) {
                    int nmask = mask | (1<<i);
                    for(int j = 0; j < 4; j++) {
                        string nu = u;
                        nu[i] = ADN[j];
                        ii next = ii(nu, nmask);
                        if(!seen.count(next)) {
                            seen.insert(next);
                            q1.push(nu);
                            q2.push(nmask);
                        }
                    }
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto &x : ans) {
            cout << x << "\n";
        }

    }

}
