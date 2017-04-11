#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 32780;
const double EPS = 1e-5;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    string a, b;
    while(cin >> a >> b) {
        vector<int> cnta(26), cntb(26);
        for(int i = 0; i < a.size(); i++) {
            cnta[ a[i]-'A' ]++;
        }
        for(int i = 0; i < b.size(); i++) {
            cntb[ b[i]-'A' ]++;
        }

        sort(cnta.begin(), cnta.end());
        sort(cntb.begin(), cntb.end());

        if(cnta == cntb) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}
