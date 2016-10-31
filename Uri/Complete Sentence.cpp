#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


int main() {
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string line; getline(cin, line);
        set<char> all;
        for(int i = 0; i < line.size(); i++) {
            if(line[i] >= 'a' && line[i] <= 'z') {
                all.insert(line[i]);
            }
        }
        int x = all.size();
        if(x == 26) cout << "frase completa\n";
        else if(x >= 13) cout << "frase quase completa\n";
        else cout << "frase mal elaborada\n";
    }

}
