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

    string line;
    while(getline(cin, line) && line != "*") {
        stringstream ss(line);
        string x;
        ss >> x;
        char c = tolower(x[0]);
        bool ok = true;
        while(ss >> x) {
            ok &= tolower(x[0]) == c;
        }
        if(ok) cout << "Y\n";
        else cout << "N\n";
    }

}
