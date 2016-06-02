/* USER: 308958 (osdajigu) */
/* PROBLEM: 36 (100 - The 3n + 1 problem) */
/* SUBMISSION: 14247835 */
/* SUBMISSION TIME: 2014-09-22 22:26:11 */
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
#define MAX 1000000 + 5
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

int i, j, ans = 0, cont;
int main() {
    while(cin >> i >> j) {
        ans = 0;
        cout << i << " " << j << " ";
        if(i > j) {
            int q = j;
            j = i;
            i = q;
        }
        for(int k = i; k <= j; k++) {
            cont = 0;
            int aux = k;
            while(aux != 1) {
                cont++;
                //cout << aux << " ";
                //system("pause");
                if(aux % 2 == 1)
                    aux = 3 * aux + 1;
                else
                    aux = aux / 2;
            }
            //ans = max(ans, (k == 1 ? cont : ++cont));
            ans = max(ans, ++cont);
        }

        cout << ans << endl;

    }
    return 0;
}
