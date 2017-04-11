#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 10;
const double EPS = 1e-5;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> program(1440);
        map<string, int> id;
        map<int, string> rid;
        int tag = 0;
        for(int i = 0; i < n; i++) {
            int a, b; char c; cin >> a >> c >> b;
            int x, y; char z; cin >> x >> z >> y;
            string name; cin >> name;
            id[name] = ++tag;
            rid[tag] = name;
            int t = x*60+y, s = a*60+b;
            if(t == 0) t = 1440;
            for(int j = s; j < t; j++) {
                program[j] = tag;
            }
        }

        vector<int> next(1440);
        next[1440-1] = program[0];
        for(int i = 1440-2; i >= 0; i--) {
            if(program[i] == program[i+1]) next[i] = next[i+1];
            else next[i] = program[i+1];
        }

        int q; cin >> q;
        while(q--) {
            int a, b; char c; cin >> a >> c >> b;
            int t = a*60+b;
            cout << rid[ next[t] ] << "\n";
        }
    }

}
