#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e2 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

ll a, b;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> a >> b >> s) {

        vector<bool> seen(s.size(), false);
        vector<int> pos;
        int black = 0, last = 0;
        for(int i = 0; i < s.size(); i++) if(s[i] == 'B') {
            black++;
            seen[i] = true;
            pos.PB(i);
        }

        int j = pos.size() - 1;
        ll ans = 0;
        for(int i = 0; i < black; i++) {
            if(seen[i]) continue;
            ans += min((a - b)*(ll)abs(i - pos[j]), a);
            j--;
        }

        cout << ans << "\n";

    }



}



