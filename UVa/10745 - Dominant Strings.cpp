#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 1010;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> cnt;
    vector<string> all;
    string s;
    int i = 0;
    while(cin >> s) {
        all.push_back(s);
        cnt.push_back(vector<int>(26));
        for(int j = 0; j < s.size(); j++) {
            cnt[i][ s[j]-'a' ]++;
        }
        i++;
    }
    vector<string> ans;
    for(i = 0; i < all.size(); i++) {
        bool dominating = true;
        for(int j = 0; j < all.size() && dominating; j++) {
            if( i == j ) continue;
            bool ok = true;
            for(int k = 0; k < 26 && ok; k++) {
                if(cnt[i][k]) {
                    ok &= cnt[i][k] <= cnt[j][k];
                }
            }
            dominating &= !ok;
        }
        if(dominating)
            ans.push_back(all[i]);
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

}
