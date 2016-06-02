#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 150
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int x[MAX], y[MAX], w[MAX], n;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(scanf("%d", &n) > 0) {
        double xsum = 0, ysum = 0, wsum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &w[i]);
            xsum += x[i] * w[i];
            ysum += y[i] * w[i];
            wsum += w[i];
        }

        double X = xsum / wsum;
        double Y = ysum / wsum;

        double ans = 0;
        for(int i = 0; i < n; i++) {
            ans += w[i] * ((X - x[i])*(X - x[i]) + (Y - y[i])*(Y - y[i]));
        }

        printf("%.3lf\n", ans);

    }
}
