/* USER: 308958 (osdajigu) */
/* PROBLEM: 1637 (10696 - f91) */
/* SUBMISSION: 14654654 */
/* SUBMISSION TIME: 2014-12-10 18:17:17 */
/* LANGUAGE: 3 */

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
#include<utility>
#include<sstream>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 1000000 + 10
#define LIMIT 1000000
#define MOD 1000000007
using namespace std;

int N;
int dp[MAX];

int solve(int N){
    if(dp[N] != -1) return dp[N];
    if(N >= 101) return dp[N] = N - 10;
    return dp[N] = solve(solve(N + 11));
}

int main() {
    memset(dp, -1, sizeof(dp));
    while(cin >> N && N != 0) {
        cout << "f91(" << N << ") = " << solve(N) << endl;
    }

}
