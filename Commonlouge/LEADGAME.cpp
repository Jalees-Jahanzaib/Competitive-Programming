#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 21;
const double EPS = 1e-5;
const int INF = INT_MAX/4;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n; cin >> n;
    int max_lead = -1, p = -1, p1 = 0, p2 = 0;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p1 += a; p2 += b;
        if(p1-p2 > max_lead) {
            max_lead = p1-p2;
            p = 1;
        } else if(p2-p1> max_lead) {
            max_lead = p2-p1;
            p = 2;
        }
    }

    cout << p << " " << max_lead << "\n";


}
