#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int MOD = 1000000007;
const int MAX = 1010;

int main() {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    string line;
    while(getline(cin, line)) {
        istringstream ss(line);
        char x;
        vector<char> all;
        while(ss >> x) all.push_back(x);

        reverse(all.begin(), all.end());
        bool ok = true, zero = false;
        stack<ll> st;
        for(int i = 0; i < all.size(); i++) {
            if(all[i] == '+' || all[i] == '-' || all[i] == '/' || all[i] == '*') {
                if(st.size() < 2) {
                    ok = false;
                    break;
                }
                ll a = st.top(); st.pop();
                ll b = st.top(); st.pop();
                if(all[i] == '/' && a == 0) {
                    zero = true;
                    a = 1;
                }
                if(all[i] == '+') st.push(b+a);
                if(all[i] == '-') st.push(b-a);
                if(all[i] == '*') st.push(b*a);
                if(all[i] == '/') st.push(b/a);
            } else {
                st.push(all[i]-'0');
            }
        }

        ok &= st.size() == 1;

        if(ok) {
            if(zero) cout << "Division by zero.\n";
            else cout << "The answer is " << st.top() << ".\n";
        }
        else {
            cout << "Invalid expression.\n";
        }
    }
}
