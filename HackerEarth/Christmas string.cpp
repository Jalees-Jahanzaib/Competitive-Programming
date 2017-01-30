#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> ii;
const int MOD = 1000000007;
const int MAX = 20010;

int main() {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    string s; cin >> s;
    int n; cin >> n;
    vector<int> cnt(s.size());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string line; cin >> line;
        int fails = 0, pos;
        for(int j = 0; j < line.size(); j++) {
            if(line[j] != s[j] && s[j] != '*') {
                fails++;
                pos = j;
            }
        }
        if(fails == 0) ans++;
        else if(fails == 1) cnt[pos]++;
    }
    int best = 0;
    for(int i = 0; i < s.size(); i++) {
        best = max(best, cnt[i]);
    }

    cout << best + ans << "\n";
}
