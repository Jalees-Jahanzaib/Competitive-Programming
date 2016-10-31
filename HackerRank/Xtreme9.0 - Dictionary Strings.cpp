#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> need(30, 0);
        for(int i = 0; i < n; i++) {
            vector<int> all(30, 0);
            string word; cin >> word;
            for(int j = 0; j < word.size(); j++) {
                all[ word[j] - 'a' ]++;
            }
            for(int j = 0; j < 30; j++) {
                need[j] = max(need[j], all[j]);
            }
        }
        while(m--) {
            string word; cin >> word;
            vector<int> all(30, 0);
            for(int j = 0; j < word.size(); j++) {
                all[ word[j] - 'a' ]++;
            }

            int sz = word.size(), missed = 0;
            bool ok = true;

            for(int i = 0; i < 30; i++) {
                sz -= need[i];
                if(need[i] > all[i]) {
                    missed += need[i] - all[i];
                    ok = false;
                }
            }

            if(!ok) {
                cout << "No " << missed << "\n";
            }
            else {
                cout << "Yes " << (sz == 0 ? "Yes" : "No") << "\n";
            }
        }
    }

}
