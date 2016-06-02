/* USER: 308958 (osdajigu) */
/* PROBLEM: 1039 (10098 - Generating Fast) */
/* SUBMISSION: 14655119 */
/* SUBMISSION TIME: 2014-12-10 19:57:41 */
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
int nTest;
string s;

void solve(){
    for(int i = s.size() - 2; i >= 0; i--) {
        if(s[i] < s[i + 1]) {
            for(int p = s.size() - 1; p >= 0; p--) {
                if(s[p] > s[i]) {
                    char aux = s[p];
                    s[p] = s[i];
                    s[i] = aux;
                    reverse(s.begin() + i + 1, s.end());
                    cout << s << endl;
                    solve();
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> nTest;
    while(nTest--) {
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << endl;
        solve();
        cout << endl;
    }
}
