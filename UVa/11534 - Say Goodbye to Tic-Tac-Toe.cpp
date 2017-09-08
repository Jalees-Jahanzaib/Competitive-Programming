#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 2e5+1;

const int X = 0;
const int O = 1;
const int ANY = 2;

int dp[104][4][4];

int grundy(int len, int l, int r) {
    if(len == 0) return 0;
    if(len == 1) {
        if(l == ANY || r == ANY) return 1;
        if(l == r) return 1;
        return 0;
    }
    int &ret = dp[len][l][r];
    if(ret == -1) {
        set<int> mex;
        if(l == O || l == ANY)
            mex.insert( grundy(len-1, X, r) ); /// pongo O
        if(l == X || l == ANY)
            mex.insert( grundy(len-1, O, r) ); /// pongo X
        if(r == O || r == ANY)
            mex.insert( grundy(len-1, l, X) ); /// pongo O
        if(r == X || r == ANY)
            mex.insert( grundy(len-1, l, O) ); /// pongo X

        for(int i = 1; i <= len-2; i++) {
            int a = grundy(i, l, X) ^ grundy(len-i-1, X, r); /// pongo O
            int b = grundy(i, l, O) ^ grundy(len-i-1, O, r); /// pongo X
            mex.insert(a);
            mex.insert(b);
        }

        ret = 0;
        while(mex.count(ret))
            ret++;
    }
    return ret;
}

int get(char c) {
    if(c == 'O') return X;
    if(c == 'X') return O;
    return ANY;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    memset(dp, -1, sizeof dp);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int res = 0, len = 0, moves = 0;
        char last = ' ';
        s.push_back('%');
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '.') {
                len++;
            }
            if(s[i] != '.') {
                moves++;
                if(len != 0) {
                    /// new game
                    res ^= grundy(len, get(last), get(s[i]));
                    len = 0;
                    last = ' ';
                }
                last = s[i];
            }
        }
        moves--;
        if(moves & 1) { /// computer
            !res ? cout << "Possible." : cout << "Impossible.";
            cout << endl;
        } else { /// alice
            res ? cout << "Possible." : cout << "Impossible.";
            cout << endl;
        }
    }
}
