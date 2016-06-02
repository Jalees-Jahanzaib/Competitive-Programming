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

long long N;

int main() {
    int cases = 1;
    while(cin >> N) {
        if(N == 0L) return 0;
        cout << "Case " << cases++ << ": " << (long) (5L + sqrt(25L - 4L * (6L - 2L * N))) / 2L << endl;
    }
}
