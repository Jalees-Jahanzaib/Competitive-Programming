/* USER: 308958 (osdajigu) */
/* PROBLEM: 1717 (10776 - Determine The Combination) */
/* SUBMISSION: 14655616 */
/* SUBMISSION TIME: 2014-12-10 23:56:13 */
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
#define MAX 30 + 5
#define LIMIT 1000000
#define MOD 1000000007
using namespace std;
int n;
string s;
map<string, bool> dp;

void solve(string cur, int index) {
    //sort( cur.begin(), cur.end());
    if( dp[cur]) return;
    dp[cur] = true;
    if(cur.size() == n) {
        cout << cur << endl;
        return;
    }
    for(int i = index + 1; i < s.size(); i++) {
            solve(cur + s[i], i);
    }
}

int main() {
    while(cin >> s >> n) {
        sort(s.begin(), s.end());
        dp.clear();
        solve("", -1);
    }
}
