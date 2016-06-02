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
#define ii pair<int, int>
#define PB push_back
#define checkk x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 3 * (int(1e5) + 10)
#define INF LONG_LONG_MAX / 6;
#define INF2 LONG_LONG_MAX / 6
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

struct Square {
    double x1, x2, y1, y2;

    Square(double x1, double x2, double y1, double y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin)

    char m;
    double x, y, c, d;
    vector<Square> v;
    while(cin >> m && m != '*') {
        cin >> x >> y >> c >> d;
        v.PB(Square(x, c, y, d));
    }

    vector<dd> p;
    int j = 0;
    while(cin >> x >> y && (x != 9999.9 || y != 9999.9)) {
        j++;
        bool flag = false;
        for(int i = 0; i < v.size(); i++) {
            double maxx = fmax(v[i].x1, v[i].x2);
            double minx = fmin(v[i].x1, v[i].x2);
            double maxy = fmax(v[i].y1, v[i].y2);
            double miny = fmin(v[i].y1, v[i].y2);

            if(x > minx && x < maxx && y > miny && y < maxy) {
                flag = true;
                cout << "Point " << j << " is contained in figure " << i + 1 << "\n";
            }
        }

        if(!flag) cout << "Point " << j << " is not contained in any figure\n";
    }


}
