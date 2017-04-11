#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 10001;
const double EPS = 1e-5;
const int INF = INT_MAX;

int res[2][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        s.push_back('=');
        memset(res, 0, sizeof res);
        int cur_n = 0, side = 0, x = false, sign = 1, really_zero = 0;
        for(int i = 0; i < s.size(); i++) {
            assert(s[i] != ' ');
            if(s[i] == 'x') {
                if(cur_n == 0 && !really_zero) cur_n = 1;
                really_zero = false;
                x = true;
            } else if(s[i] == '=') {
                res[side][x] += sign*cur_n;
                cur_n = 0;
                ++side;
                x = false;
                sign = 1;
            } else if(s[i] == '+') {
                res[side][x] += sign*cur_n;
                cur_n = 0;
                x = false;
                sign = 1;
            } else if(s[i] == '-') {
                res[side][x] += sign*cur_n;
                cur_n = 0;
                x = false;
                sign = -1;
            }
            else { /// is a number
                cur_n = cur_n*10 + (s[i]-'0');
                really_zero = cur_n == 0;
            }
        }
//        cout << res[0][0] << " " << res[0][1] << " = " << res[1][0] << " " << res[1][1] << endl;
        if(res[0][0] == res[1][0] && res[0][1] == res[1][1]) cout << "IDENTITY\n";
        else {
            int a = res[0][0] - res[1][0];
            int b = res[1][1] - res[0][1];
            if(b != 0) cout << int(floor((a*1.0)/b)) << "\n";
            else cout << "IMPOSSIBLE\n";
        }

    }
//    cerr << -1/3 << endl;
//    cerr << floor(-1.0/3.0) << endl;
}
