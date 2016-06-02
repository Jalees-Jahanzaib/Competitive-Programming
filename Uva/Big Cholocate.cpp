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
int N, M;

int main() {
    while(cin >> N >> M) {
        int lines = min(N, M);
        int curCuts = min(N, M) - 1;
        curCuts += ((lines) * (max(N, M) - 1));
        cout << curCuts << endl;
    }
}
