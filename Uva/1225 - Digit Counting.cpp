/* USER: 308958 (osdajigu) */
/* PROBLEM: 3666 (1225 - Digit Counting) */
/* SUBMISSION: 14339640 */
/* SUBMISSION TIME: 2014-10-12 02:32:49 */
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
#define PB push_back
#define EPS 0.00000001
#define MAX 100000 + 5
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;


int n, nTest;
int ans[10];

int main() {
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    cin >> nTest;
    while(nTest--) {
        memset(ans, 0, sizeof(ans));
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int tmp = i;
            while(tmp) {
                ans[tmp % 10]++;
                tmp /= 10;
            }
        }
        for(int i = 0; i < 9; i++) {
            cout << ans[i] << " ";
        }
        cout << ans[9] << endl;
    }
}
