#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;

int main() {

    int n;
    while(cin >> n && n != 0) {
        for(int i = 1; ; i++) {
            bool found = false;
            vector<int> seen(n);
            for(int j = 0; j < n; j++) seen[j] = j;
            for(int cur = 0; ; cur = (cur + i) % int(seen.size()) ) {
                seen.erase(seen.begin() + cur);
                cur--;
                if(int(seen.size()) == 1) {
                    found = seen[0] == 12;
                    break;
                }
            }
//            cout << endl;
            if(found) {
                cout << i << "\n";
                break;
            }
        }

    }



}
