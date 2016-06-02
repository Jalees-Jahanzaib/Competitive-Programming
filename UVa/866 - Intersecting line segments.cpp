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

struct Line {
    int A, B, C, x1, y1, x2, y2;

    Line() {}
    Line(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {
        A = y2 - y1;
        B = x1 - x2;
        C = A*x1 + B*y1;
    }
};

bool intersect(Line a, Line b) {
    double det = a.A*b.B - b.A*a.B;
    if(det == 0) return false;
    double x = (b.B*a.C - a.B*b.C) / det;
    double y = (a.A*b.C - b.A*a.C) / det;

    if(x <= max(a.x1, a.x2) && x >= min(a.x1, a.x2) &&
       y <= max(a.y1, a.y2) && y >= min(a.y1, a.y2) &&
       x <= max(b.x1, b.x2) && x >= min(b.x1, b.x2) &&
       y <= max(b.y1, b.y2) && y >= min(b.y1, b.y2))
        return true;

    return false;
}

int T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin)

    cin >> T;

    bool first = true;
    while(T--) {
        if(first) first = false;
        else cout << "\n";

        cin >> N;

        vector<Line> lines;
        int a, b, c, d;
        for(int i = 0; i < N; i++) {
            cin >> a >> b >> c >> d;
            lines.PB(Line(a, b, c, d));
        }

        int ans = lines.size();
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++) {
                if(intersect(lines[i], lines[j]))
                    ans += 2;
            }

        cout << ans << "\n";
    }
}
