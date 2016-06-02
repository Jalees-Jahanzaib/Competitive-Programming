#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 400100
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int k, phi[MAX];
string p, t;

string change(string &s) {
    s = "." + s;
    string ans = "";
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == ')' || s[i] == '(') ans += s[i];
        else if(s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') ans += "+";
        else if(s[i] >= 'a' && s[i] <= 'z') ans += "a";
        else if(!(s[i - 1] >= '0' && s[i - 1] <= '9')) ans += "a";
    }
    return ans;
}

int kmp() {
    int ans = 0;

    phi[0] = k = -1;
    for(int i = 1; i <= p.size(); i++) {
        while( k > -1 && p[k] != p[i-1]) k = phi[k];
        phi[i] = ++k;
    }

    k = 0;
    for(int i = 0; i < t.size(); i++) {
        while(k > -1 && p[k] != t[i]) k = phi[k];
        ++k;
        if(k == p.size()) ans++, k = phi[k];
    }

    return ans;

}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> p >> t) {
        p = change(p); t = change(t);
        cout << kmp() << "\n";
    }
}
