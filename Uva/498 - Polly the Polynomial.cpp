/* USER: 308958 (osdajigu) */
/* PROBLEM: 439 (498 - Polly the Polynomial) */
/* SUBMISSION: 14575605 */
/* SUBMISSION TIME: 2014-11-23 20:29:26 */
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
#define MAX 100000000
#define LIMIT 1000000
#define MOD 1000000007
#define ll long long

using namespace std;

vector<ll> c, x;
ll aux;

string s, s1;
int main() {
    while(getline(cin, s)) {
        c.clear();
        x.clear();
        getline(cin, s1);
        stringstream ss(s);
        while(ss >> aux)
            c.PB(aux);
        stringstream ss1(s1);
        while(ss1 >> aux)
            x.PB(aux);
        for(int i = 0; i < x.size(); i++) {
            ll current = c[0];
            for(int j = 1; j < c.size(); j++) {
                current *= x[i];
                current += c[j];
            }
            if(!i) cout << current;
            else cout << " " << current;
        }
        cout << endl;
    }
}
