#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 10;
const double EPS = 1e-5;
const int INF = INT_MAX;
const ll MOD = int(1e9) + 7;

int phi[MAX];

int KMP (string &p, string &t) {
    int matches = 0;
    phi[0] = -1;
    for (int i = 0, j = -1; i < p.size();) {
        while( j > -1 && p[j] != p[i]) j = phi[j];
        i++; j++;
        phi[i] = j;
    }
    for(int i = 0, j = 0; i < t.size();) {
        while(j > -1 && p[j] != t[i]) j = phi[j];
        i++; j++;
        if(j == p.size()) {
            matches++, j = 0;
        }
    }
    return matches;
}

bool first = true;

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        if(!first) cout << "\n";
        first = false;
        string s; cin >> s;
        int n = s.size();
        string p;
        for(int i = 0; i < s.size(); i++) {
            p.push_back(s[i]);
            int m = KMP(p, s);
            if(n % (i+1) == 0 && m == n/(i+1)) {
                cout << i+1 << "\n";
                break;
            }
        }
    }


}
