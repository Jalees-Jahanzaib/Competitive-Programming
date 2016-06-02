/* USER: 308958 (osdajigu) */
/* PROBLEM: 1281 (10340 - All in All) */
/* SUBMISSION: 14599699 */
/* SUBMISSION TIME: 2014-11-28 21:24:33 */
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
#define MP make_pair
#define EPS 0.00000001
#define MAX 1000000 * 2 + 10
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
string s1, s2;
int main() {
    while(cin >> s1 >> s2) {
        int j = 0, i = 0;
        while(j < s1.size() && i < s2.size())
            if(s1[j] == s2[i]) j++, i++;
            else i++;
        if(j == s1.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
