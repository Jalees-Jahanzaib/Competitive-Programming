#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e5 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int n;
bool even;
string init, lt;

bool can(string &s) {
    bool ok = false;
    string ans = s, tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(even && s.size() * 2 == init.size()) {
        ans += tmp;
        ok |= (ans > init);
    }
    else if(!even && s.size() * 2 - 1 == init.size()) {
        ans += tmp.substr(1);
        ok |= (ans > init);
    }
    else {
        ok = true;
        if(even) {
            ans += tmp;
        }
        else {
            ans += tmp.substr(1);
        }
    }

    if(ok)
        cout << ans << "\n";

    return ok;
}

string add(string s) {
    bool carry = true;
    for(int i = s.size() - 1; i >= 0 && carry; i--) {
        carry = s[i] == '9';
        if(s[i] == '9') s[i] = '0';
        else s[i] += 1;
    }
    if(carry)
        if(!even) {
            s = "1" + string(s.size() - 1, '0');
            even = !even;
        }
        else {
            s = "1" + string(s.size(), '0');
            even = !even;
        }

    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n >> init) {
        even = init.size() % 2 == 0;
        lt = init.substr(0, (init.size() + 1) / 2);
        for(int i = 0; i < n;) {
            if(can(lt))
                i++;
            lt = add(lt);
        }
    }



}
