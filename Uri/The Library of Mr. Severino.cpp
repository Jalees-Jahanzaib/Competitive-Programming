#include<bits/stdc++.h>
#include<time.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<double, ii> iii;

const int MAX = 200005;
const double EPS = 1e-5;
const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

//    srand(time(0));

    int n;
    while(cin >> n) {
        vector<string> all(n);
        for(int i = 0; i < n; i++) cin >> all[i];
        sort(all.begin(), all.end());
        for(int i = 0; i < n; i++) cout << all[i] << "\n";
    }
}
