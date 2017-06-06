#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 100;
const int INF = INT_MAX/3;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

string board[MAX];

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        vector<int> v(100);
        int pointer = 0;
        string line; cin >> line;
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == '>') pointer = (pointer+1)%100;
            if(line[i] == '<') pointer = (pointer-1+100)%100;
            if(line[i] == '+') v[pointer]++;
            if(line[i] == '-') v[pointer]--;
        }
        cout << "Case " << ++cases << ":";
        for(int i = 0; i < 100; i++) {
            stringstream ss;
            ss << " " << setfill('0') << setw(2) << hex << v[i];
            string x = ss.str();
            if(x.size() > 3) x = " " + x.substr(x.size() - 2);
            for(int j = 1; j < x.size(); j++) {
                x[j] = toupper(x[j]);
            }
            cout << x;
        }
        cout << "\n";
    }
}

