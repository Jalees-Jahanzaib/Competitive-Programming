#include <iostream>

#define MP make_pair
#define MAX int( 1e3+100 )

using namespace std;

int n;
int dp[MAX], p[MAX];

struct Data {
    int id, w, s;
    bool operator < (const Data &o)const {
        if(w != o.w) return w < o.w;
        return s > o.s;
    }
}d[MAX];

pair<int, int> lis() {
    int maxLength = 1, bestEnd = 0;

    dp[0] = 1;
    p[0] = -1;

    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        p[i] = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(dp[j] + 1 > dp[i] && d[j].w < d[i].w && d[j].s > d[i].s) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
        if(dp[i] > maxLength) {
            maxLength = dp[i];
            bestEnd = i;
        }
    }

    return MP(maxLength, bestEnd);
}

void repath(int cur) {
    if(p[cur] != -1) repath(p[cur]);
    cout << d[cur].id + 1 << "\n";
}

int main() {
    freopen( "input.txt" , "r", stdin  );

    while(cin >> d[n].w >> d[n].s) d[n].id = n++;

    sort(d, d + n);
    if(n == 0) cout << "0\n";
    else {
        pair<int, int> ans = lis();
        cout << ans.first << "\n";
        repath(ans.second);
    }

    return 0;
}
