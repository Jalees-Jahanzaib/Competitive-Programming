#include<bits/stdc++.h>

#define MAX 100

using namespace std;

int n, m, q, v[30], acc[30];
string board[MAX];
string word;

bool count(string &w) {
    memset(acc, 0, sizeof acc);
    for(int i = 0, j = 0; i < w.size() && j < w.size(); i++) {
        while(j < w.size() && j-i+1 <= word.size()) {
            acc[ w[j]-'a' ]++;
            j++;
        }
        bool same = true;
        for(int k = 0; k < 26 && same; k++)
            same &= acc[k] == v[k];
        if(same) return true;

        acc[ w[i]-'a' ]--;
    }
    return false;
}

bool solve() {
    bool ans = false;
    for(int i = 0; i < n && !ans; i++) {
        ans |= count(board[i]);

        string cur = "";
        for(int x = i, y = 0; x < n && y < m; x++, y++) cur.push_back(board[x][y]);
        ans |= count(cur);

        cur = "";
        for(int x = i, y = 0; x >= 0 && y < m; x--, y++) cur.push_back(board[x][y]);
        ans |= count(cur);

    }
    for(int i = 0; i < m && !ans; i++) {
        string cur = "";
        for(int j = 0; j < n; j++) cur.push_back(board[j][i]);
        ans |= count(cur);

        cur = "";
        for(int x = 0, y = i; x < n && y < m; x++, y++) cur.push_back(board[x][y]);
        ans |= count(cur);

        cur = "";
        for(int x = n-1, y = i; x >= 0 && y < m; x--, y++) cur.push_back(board[x][y]);
        ans |= count(cur);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m >> q) {
        for(int i = 0; i < n; i++) {
            cin >> board[i];
        }

        int ans = 0;
        for(int i = 0; i < q; i++) {
            memset(v, 0, sizeof v);
            cin >> word;
            for(int j = 0; j < word.size(); j++)
                v[ word[j]-'a' ]++;
            ans += solve();
        }

        cout << ans << "\n";
    }
}
