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
#define MAX 50 + 5
#define LIMIT 1000000
#define MOD 1000000007

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8

using namespace std;

int nTest, N, ans;
stack<int> peg[MAX];

void dfs() {

    for(int i = 0; i < N; i++)
        if(peg[i].empty()) {
            peg[i].push(ans + 1);
            i = -1;
            ans += 1;
        }
        else if(pow((int)sqrt(peg[i].top() + (ans + 1)), 2) == peg[i].top() + (ans + 1)) {
                peg[i].push(ans + 1);
                i = -1;
                ans += 1;
        }
}


int main() {
    cin >> nTest;
    while(nTest--) {
        cin >> N;
        for(int i = 0; i < N; i++) peg[i] = stack<int>();
        ans = 0;
        dfs();
        cout << ans << endl;
    }
}

