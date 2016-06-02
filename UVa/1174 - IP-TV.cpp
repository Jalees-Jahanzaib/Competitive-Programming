/* USER: 308958 (osdajigu) */
/* PROBLEM: 3615 (1174 - IP-TV) */
/* SUBMISSION: 15112903 */
/* SUBMISSION TIME: 2015-03-10 01:08:28 */
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
#define MAX 10000 + 10

using namespace std;

struct Edge {
    string from, to;
    int cost;
    bool operator < (const Edge &e) const {
        return (this -> cost < e.cost);
    }
};

int nTest, M, N, cases;
char a[10], b[10];
vector<Edge> edges;
map<string, string> father;

string find(string x) {
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

void merge(string a, string b){
    string A = find(a);
    string B = find(b);
    father[A] = B;
}


void kruskal() {
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if(find(e.from) != find(e.to)) {
            merge(e.from, e.to);
            ans += e.cost;
        }
    }
    if(cases == 0) printf("%d\n", ans);
    else printf("\n%d\n", ans);
    cases++;
}

int main() {
    scanf("%d", &nTest);
    while(nTest--) {
        father.clear();
        edges.clear();
        scanf("%d%d", &M, &N);
        Edge e;
        for(int i = 0; i < N; i++) {
            scanf("%s%s%d", a, b, &e.cost);
            e.from = string(a);
            e.to = string(b);
            edges.PB(e);
            if(father[e.from] == "") father[e.from] = e.from;
            if(father[e.to] == "") father[e.to] = e.to;
        }
        kruskal();
    }
}
