#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 105;
const double EPS = 1e-5;
const int INF = INT_MAX;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

    int n, m, c; cin >> n >> m >> c;
    int ans = 0, cur = n + m;
    while(cur >= c) {
        ans += cur/c;
        cur = cur/c + cur%c;
    }
    cout << ans << "\n";

}
