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
int ans[10000][10];

void precalc() {
    for(int i = 1; i <= 10000; i++) {
        for(int j = 0; j < 10; j++) {
            ans[i][j] = ans[i - 1][j];
        }
        int tmp = i;
        while(tmp) {
            ans[i][tmp % 10]++;
            tmp /= 10;
        }
    }
}

int main() {

    precalc();
    cin.tie(0);
    ios_base::sync_with_stdio(0);
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

