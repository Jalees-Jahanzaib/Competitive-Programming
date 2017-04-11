#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 32780;
const double EPS = 1e-5;
const int INF = INT_MAX;

void doit(vector<int> &problem, vector<bool> &done, int t, char p, string &v, int &ans, int &problems) {
    if(v == "wrong") {
        problem[ p-'A' ] += 20;
    } else {
        if(!done[ p-'A' ]) {
            ans += problem[ p-'A' ] + t;
            problems++;
        }
        done[ p-'A' ] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY
    int t;
    while(cin >> t) {
        if(t == -1) {
            cout << "0 0\n";
            continue;
        }
        int problems = 0, penaltie = 0, ans = 0;
        vector<int> problem(26);
        vector<bool> done(26);
        char p; string v; cin >> p >> v;
        doit(problem, done, t, p, v, ans, problems);
        while(cin >> t && t != -1) {
            cin >> p >> v;
            doit(problem, done, t, p, v, ans, problems);
        }
        cout << problems << " " << ans << "\n";

    }
}
