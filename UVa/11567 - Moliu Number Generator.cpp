/* USER: 308958 (osdajigu) */
/* PROBLEM: 2614 (11567 - Moliu Number Generator) */
/* SUBMISSION: 14766788 */
/* SUBMISSION TIME: 2015-01-05 20:04:49 */
/* LANGUAGE: 3 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>
#define PB push_back
#define ii pair<int, int>
#define MP make_pair
#define MAX 100000000

typedef long long ll;

using namespace std;

int dp[MAX];
ll S;

int solve(ll S) {
    //cout << S <<" "<<n << endl;
    //system("Pause");
    if(S == 0) return 0;
    if(S == 1) return 1;
    if(S <= MAX) {
        if(dp[S] != -1) return dp[S];
        if(S % 2ll == 0) return dp[S] = solve(S / 2ll) + 1;
        return dp[S] = min(solve(S - 1ll), solve(S + 1ll)) + 1;
    }
    else {
        if(S % 2ll == 0) return solve(S / 2ll) + 1;
        return min(solve(S - 1ll), solve(S + 1ll)) + 1;
    }

}

int main() {
    memset(dp, -1, sizeof(dp));
    while(cin >> S)
        cout << solve(S) << endl;

}
