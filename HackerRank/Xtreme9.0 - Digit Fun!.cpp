#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string line;
    while(cin >> line && line != "END") {
        int sz = line.size();
        if(line == "1") cout << 1 << "\n";
        else if(sz == 1) cout << 2 << "\n";
        else if(sz <= 9) cout << 3 << "\n";
        else cout << 4 << "\n";
    }
}
