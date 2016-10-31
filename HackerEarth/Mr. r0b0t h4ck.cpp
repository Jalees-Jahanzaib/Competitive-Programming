#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s, e;
        cin >> s >> e;
        for(int i = 0; i < s.size(); i++)
            cout << bitset<8>(s[i]^e[i]);
        cout << "\n";
    }

}
