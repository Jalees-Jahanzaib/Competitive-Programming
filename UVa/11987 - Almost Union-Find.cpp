/* USER: 308958 (osdajigu) */
/* PROBLEM: 3138 (11987 - Almost Union-Find) */
/* SUBMISSION: 15101367 */
/* SUBMISSION TIME: 2015-03-08 00:58:57 */
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

#define ii pair<int, int>
#define PB push_back
#define MAX 100000

using namespace std;

int n, m, op, p, q;
int father[2 * MAX + 10], sum[2 * MAX + 10], nodes[2 * MAX + 10];

void init() {
    for(int i = 1; i <= MAX; i++) {
        father[i] = i + MAX;
        father[i + MAX] = i + MAX;
        sum[i + MAX] = i;
        nodes[i + MAX] = 1;
    }
}

int find(int x) {
    return father[x] = (x == father[x] ? x : find(father[x]));
}

void solve() {
    if(op == 3) {
        printf("%d %d\n", nodes[find(p)], sum[find(p)]);
        return;
    }
    int fatherP = find(p), fatherQ = find(q);
    if(fatherP == fatherQ) return;
    if(op == 1) {
        father[fatherP] = fatherQ;
        sum[fatherQ] += sum[fatherP];
        nodes[fatherQ] += nodes[fatherP];
        return;
    }
    father[p] = fatherQ;
    sum[fatherP] -= p;
    nodes[fatherP] -= 1;
    sum[fatherQ] += p;
    nodes[fatherQ] += 1;
}

int main() {
    while(scanf("%d%d", &n, &m) > 0) {
        init();
        for(int i = 0; i < m; i++) {
            scanf("%d", &op);
            if(op == 3) scanf("%d", &p);
            else scanf("%d%d", &p, &q);
            solve();
        }
    }

}
