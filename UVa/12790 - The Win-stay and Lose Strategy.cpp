#include<bits/stdc++.h>

#define ll long long
#define dd pair<double, double>
#define ii pair<int, double>
#define PB push_back
#define checkk x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX int(1e4 + 10)
#define INF LONG_LONG_MAX / 6;
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2
#define PI acos(-1)

using namespace std;

/// 0 -> S
/// 1 -> R
/// 2 -> P
int game[3][3] = {{  0 , -1,  1 },
                  {  1 ,  0, -1 },
                  { -1 ,  1,  0 },
                  };
int win[3] = {1,2,0}, nTest;
map<char, int> id;
double p[5], dp[MAX][3];
string a, b;

double solve(int idx, int state) {
    if(dp[idx][state] != INT_MIN) return dp[idx][state];
    if(idx == b.size()) return dp[idx][state] = state*1.0;

    int curB = id[b[idx]];
    if(state == 0) return dp[idx][state] = (p[0]*solve(idx + 1, game[0][curB]) + p[1]*solve(idx + 1, game[1][curB]) + p[2]*solve(idx + 1, game[2][curB]));
    else if(state == 1){
        int lastA = win[id[b[idx - 1]]];
        return dp[idx][state] = solve(idx + 1, game[win[lastA]][curB]) + state*1.0;
    }
    else {
        int lastB = id[b[idx - 1]];
        return dp[idx][state] = solve(idx + 1, game[win[lastB]][curB]) + state*1.0;
    }

    return 0.0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/

    id['S'] = 0; id['R'] = 1; id['P'] = 2;

    cin >> nTest;

    while(nTest--) {
        cin >> a >> b >> p[1] >> p[2] >> p[0];
        p[0] /= 100.0;
        p[1] /= 100.0;
        p[2] /= 100.0;

        int ans1 = 0;
        for(int i = 0; i < a.size(); i++)
            ans1 += game[id[a[i]]][id[b[i]]];

        for(int i = 0; i <= a.size(); i++)
            for(int j = 0; j < 3; j++)
                dp[i][j] = INT_MIN;

        double ans2 = solve(0, 0);
        if(ans1*1.0 < ans2) printf("%d %.4f Y\n", ans1, ans2);
        else printf("%d %.4f N\n", ans1, ans2);

    }


}
