/* USER: 308958 (osdajigu) */
/* PROBLEM: 2167 (11226 - Reaching the fix-point.) */
/* SUBMISSION: 15059984 */
/* SUBMISSION TIME: 2015-03-01 03:48:15 */
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
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>
using namespace std;
#define ii pair<double, double>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 500000 + 100
#define LIMIT 1000000
#define MOD 1000000000


int divisors[MAX];
bool seen[MAX];
int dp[MAX];

void criba(int n) {
    for(int i = 2; i <= n; i++)
        if(!seen[i]) {
            dp[i] = 1;
            for(int j = i; j <= n; j += i) {
                seen[j] = true;
                int aux = j;
                while(aux % i == 0) divisors[j] += i, aux /= i;
            }
        }
}

int solve(int x) {
    if(dp[x] != 0) return dp[x];
    if(divisors[x] == x ) return dp[x] = 1;
    return dp[x] = solve(divisors[x]) + 1;
}

struct SegTree {
    int start, end, value;
    SegTree *left, *right;
    SegTree(int start, int end) : start(start), end(end) {
        value = 0;
    }
    SegTree() {}

    void set() {
        if(start == end) {
            value = dp[start];
            left = right = NULL;
        }
        else {
            int mid = (start + end) / 2;
            left = new SegTree(start, mid);
            right = new SegTree(mid + 1, end);
            left -> set();
            right -> set();
            value = max(left -> value, right -> value);
        }
    }

    int get(int from, int to) {
        if(start == from && to == end) return value;
        int mid = (start + end) / 2;
        if(to <= mid) return left -> get(from, to);
        else if( from > mid) return right -> get(from, to);
        else return max(left -> get(from, mid), right -> get(mid + 1, to));
    }
};

int querys, cases, from, to;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    criba(500000);
    for(int i = 2; i <= 500000; i++)
        solve(i);
    scanf("%d", &querys);
    SegTree st = SegTree(2, 500000);
    st.set();
    while(querys--) {
        scanf("%d%d", &from, &to);
        printf("Case #%d:\n%d\n", ++cases, st.get(min(from, to), max(to, from)));
    }


}
