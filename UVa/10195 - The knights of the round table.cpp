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

double a, b, c;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin)


    while(cin >> a >> b >> c) {
        double s = (a + b + c) / 2.0;
        double ans = sqrt(s * (s - a) * (s - b) * (s - c));
        if(s != 0.0)
            printf("The radius of the round table is: %.3f\n", ans / s);
        else
            printf("The radius of the round table is: 0.000\n");
    }

}
