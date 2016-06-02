/* USER: 308958 (osdajigu) */
/* PROBLEM: 1341 (10400 - Game Show Math) */
/* SUBMISSION: 14316871 */
/* SUBMISSION TIME: 2014-10-06 23:52:57 */
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
#define MAX 200 + 5
#define LIMIT 1000000
#define MOD 1000000007

#define LEFT 1
#define RIGHT 0

using namespace std;

int nTest, N, aux, target;
vector<int> numbers;
string ans;
bool flag = false;
bool visited[105][64000 + 5];

string toString(int n) {
    string ans = "";
    int aux = 0;
    while(n != 0) {
        aux = n % 10;
        ans += aux + '0';
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;

}

void dfs(string theAns, int i, int res) { /// i es el siguiente
    if(visited[i][res + 32000] || flag)
        return;
    if(i == N && res != target)
        return;
    if(i == N && res == target) {
        flag = true;
        cout << theAns << "=" << target << endl;
        return;
    }
    visited[i][res + 32000] = true;
    if(abs(res + numbers[i]) <= 32000 && !flag)
        dfs(theAns + "+" + toString(numbers[i]), i + 1, res + numbers[i]);
    if(abs(res - numbers[i]) <= 32000 && !flag)
        dfs(theAns + "-" + toString(numbers[i]), i + 1, res - numbers[i]);
    if(abs(res * numbers[i]) <= 32000 && !flag)
        dfs(theAns + "*" + toString(numbers[i]), i + 1, res * numbers[i]);
    if(abs(res / numbers[i]) <= 32000 && res % numbers[i] == 0 && !flag)
        dfs(theAns + "/" + toString(numbers[i]), i + 1, res / numbers[i]);
}

int main() {
    cin >> nTest;
    while(nTest--) {
        numbers.clear();
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> aux;
            numbers.PB(aux);
        }
        cin >> target;
        ans = toString(numbers[0]);
        flag = false;
        memset(visited, false, sizeof(visited));
        dfs(ans, 1, numbers[0]);
        if(!flag)
            cout << "NO EXPRESSION\n";
    }

}
