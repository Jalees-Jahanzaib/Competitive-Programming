#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int phi[MAX];
bool dp[MAX][2];
int id = 0;

void KMP (string &p, string &t, int pre) {
    phi[0] = -1;

    for (int i = 0, j = -1; i < p.size();) {
        while( j > -1 && p[j] != p[i]) j = phi[j];
        i++; j++;
        phi[i] = j;
    }

    for(int i = 0, j = 0; i < t.size();) {
        while(j > -1 && p[j] != t[i]) j = phi[j];
        i++; j++;
        if(j == p.size()) {
            int last = i - p.size() - pre;
            if(last >= 0 && dp[last][1-id]) {
                dp[i][id] = true;
            }
            j = phi[j];
        }
    }
}

int main( ) {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string t, p;

    while( cin >> t >> p ) {
        for(int i = 0; i <= t.size(); i++) {
            dp[i][0] = true;
            dp[i][1] = false;
        }
        id = 1;
        vector<string> words;
        vector<int> pre;
        int last = 0;
        string cur = "";
        for(int i = 0; i < p.size(); i++) {
            if(cur.size() > 0 && p[i] == '?') {
                words.push_back(cur);
                pre.push_back(last);
                last = 1;
                cur = "";
            }
            else if(p[i] == '?') {
                last++;
            }
            else if(p[i] != '?'){
                cur.push_back(p[i]);
            }
        }
        if(cur.size() > 0 ) {
            words.push_back(cur);
            pre.push_back(last);
            last = 0;
        }

        if(words.size() == 0) {
            cout << max(0, int(t.size() - p.size()) + 1) << "\n";
        }
        else {
            for(int i = 0; i < words.size(); i++) {
                KMP(words[i], t, pre[i]);
                for(int j = 0; j <= t.size(); j++)
                    dp[j][1-id] = false;
                id = 1 - id;
            }
            int ans = 0;
            for(int i = t.size() - last; i >= 0; i--) {
                if(dp[i][1-id]) ans++;
            }

            cout << ans << "\n";
        }
    }
}
