#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ll long long
#define dd pair<double, double>
#define ii pair<int, ll>
#define PB push_back
#define checkk x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 3 * (int(1e5) + 10)
#define INF LONG_LONG_MAX / 6;
#define INF2 LONG_LONG_MAX / 6
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

int nTest, cases;
ll a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin)

    cin >> nTest;

    while(nTest--) {
        cin >> a >> b >> c;

        set<ll> s;
        s.insert(a); s.insert(b); s.insert(c);eometria

        cout << "Case " << ++cases << ": ";
        if(a < b + c && b < c + a && c < a + b) {
            if(s.size() == 1) cout << "Equilateral\n";
            if(s.size() == 2) cout << "Isosceles\n";
            if(s.size() == 3) cout << "Scalene\n";
        }
        else cout << "Invalid\n";
    }
}
