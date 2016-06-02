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

struct Line {
    int A, B, C, xfrom, yfrom, xto, yto;
    bool point;

    Line(int xfrom, int yfrom, int xto, int yto) {
        this -> xfrom = xfrom;
        this -> yfrom = yfrom;
        this -> xto = xto;
        this -> yto = yto;

        A = yto - yfrom;
        B = xfrom - xto;
        C = A*xfrom + B*yfrom;

        point = (xfrom == xto && yfrom == yto);
    }
};

bool inside(Line a, Line b) {
    if(min(a.xfrom, a.xto) < min(b.xfrom, b.xto) && max(a.xfrom, a.xto) > max(b.xto, b.xfrom) &&
       a.yfrom == b.yfrom && a.yto == b.yto)
        return true;
    if(min(a.yfrom, a.yto) < min(b.yfrom, b.yto) && max(a.yfrom, a.yto) > max(b.yto, b.yfrom) &&
       a.xfrom == b.xfrom && a.xto == b.xto)
       return true;
    return false;
}

bool intersect(Line a, Line b) {
    double det = a.A*b.B - a.B*b.A;
    if(det == 0) return inside(a, b);
    double x = (b.B*a.C - a.B*b.C)*1.0 / det;
    double y = (a.A*b.C - b.A*a.C)*1.0 / det;

    if(x <= max(a.xfrom, a.xto)*1.0 && x >= min(a.xfrom, a.xto)*1.0 &&
       y <= max(a.yfrom, a.yto)*1.0 && y >= min(a.yfrom, a.yto)*1.0 &&
       x <= max(b.xfrom, b.xto)*1.0 && x >= min(b.xfrom, b.xto)*1.0 &&
       y <= max(b.yfrom, b.yto)*1.0 && y >= min(b.yfrom, b.yto)*1.0)
        return true;

    return false;
}

int xstart, xend, ystart, yend, x_1, y_1, x_2, y_2, nTest;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin)

    cin >> nTest;

    while(nTest--) {
        cin >> xstart >> ystart >> xend >> yend>> x_1 >> y_1 >> x_2 >> y_2;

        if(x_1 > x_2) swap(x_1, x_2);
        if(y_2 > y_1) swap(y_2,y_1);

        if(xstart >= min(x_1, x_2) && xstart <= max(x_1, x_2) && ystart >= min(y_1, y_2) && ystart <= max(y_1, y_2) ||
           xend >= min(x_1, x_2) && xend <= max(x_1, x_2) && yend >= min(y_1, y_2) && yend <= max(y_1, y_2))
            cout << "T\n";
        else {
            vector<Line> lines;

            Line l = Line(xstart, ystart, xend, yend);
            lines.PB(Line(x_1, y_1, x_2, y_1));
            lines.PB(Line(x_2, y_1, x_2, y_2));
            lines.PB(Line(x_2, y_2, x_1, y_2));
            lines.PB(Line(x_1, y_2, x_1, y_1));
            bool ok = false;

            for(int i = 0; i < 4 && !ok; i++) {
                //lines[i].print();
                ok |= intersect(l, lines[i]);
            }

            if(ok) cout << "T\n";
            else cout << "F\n";
        }
    }

}
