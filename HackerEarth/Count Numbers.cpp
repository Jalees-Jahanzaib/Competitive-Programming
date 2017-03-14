#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 200;
const double EPS = 1e-5;
const int INF = INT_MAX/2;
const ll MOD = 1000000007;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int main() {
     ios_base::sync_with_stdio(0);
//     cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<string> all;
        string cur = "";
        s = s + '.';
        for(int i = 0; i < n+1; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                cur.push_back(s[i]);
            } else {
                if(cur.size()) {
                    all.push_back(cur);
                    cur = "";
                }
            }
        }

        cout << int(all.size()) << "\n";
    }

}
