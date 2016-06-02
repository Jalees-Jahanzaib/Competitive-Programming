/* USER: 308958 (osdajigu) */
/* PROBLEM: 1131 (10190 - Divide, But Not Quite Conquer!) */
/* SUBMISSION: 14654927 */
/* SUBMISSION TIME: 2014-12-10 19:09:22 */
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

ll n, m;
vector<ll> ans;

bool solve(ll cur) {
    ans.PB(cur);
    if(cur == 1L || cur == 0L) return true;
    if((cur % m) != 0L) return false;
    if(solve(cur / m)) return true;
    return false;
}


int main() {
    while(cin >> n >> m) {
        ans.clear();
        if(m == 0L || (n != 1L && m == 1L) || (n < m) || (n == 1)|| !solve(n)) cout << "Boring!";
        else {
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}
