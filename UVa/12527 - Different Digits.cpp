    #include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(5000 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int dp[MAX], seen[11], N, M;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    for(int i = 1, label = 1; i <= 5000; i++, label++) {
        int tmp = i;
        bool ok = true;
        while(tmp != 0) {
            if(seen[tmp % 10] == label) {
                ok = false;
                break;
            }
            seen[tmp % 10] = label;
            tmp /= 10;
        }
        if(ok) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1];
    }

    while(cin >> N >> M)
        cout << dp[M] - dp[N - 1] << "\n";


}



