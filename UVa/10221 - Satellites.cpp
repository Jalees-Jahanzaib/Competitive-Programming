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
#define PI acos(-1)

using namespace std;



int main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    //freopen("input.txt", "r", stdin)

    double dist, grade, radio = 6440.0;
    string type;

    while(cin >> dist >> grade >> type) {
        if(type == "min") grade /= 60.0;

        if(grade > 180) grade = 360.0 - grade;

        double ans1 = (grade / 360.0) * (2 * PI * (radio + dist));
        double ans2 = sin((grade / 2.0) * PI / 180.0) * (radio + dist) * 2.0;

        printf("%.6f %.6f\n", ans1, ans2);
    }

}
