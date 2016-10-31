    #include<bits/stdc++.h>

#define MOD			1000000021LL
#define MAX_N		100000

using namespace std;

typedef long long ll;
const int INF = INT_MAX/2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n && n != 0) {
        vector<char> all(n), target(n);
        for(int i = 0; i < n; i++) {
            cin >> all[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> target[i];
        }

        stack<char> s;
        for(int i = 0, j = 0; i < n && j < n; j++) {
            cout << "I";
            s.push(all[j]);
            while(!s.empty() && s.top() == target[i]) {
                s.pop();
                cout << "R";
                i++;
            }
        }
        if(!s.empty()) {
            cout << " Impossible";
        }
        cout << "\n";
    }








}
