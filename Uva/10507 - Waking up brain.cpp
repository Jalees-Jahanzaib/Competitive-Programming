/* USER: 308958 (osdajigu) */
/* PROBLEM: 1448 (10507 - Waking up brain) */
/* SUBMISSION: 15101272 */
/* SUBMISSION TIME: 2015-03-08 00:05:33 */
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
#define MAX 500

using namespace std;

int nTest, aux, aux2, N, M, counter[MAX];
vector<int> graph[MAX];
queue<ii> q;
bool seen[MAX];

void init() {
    memset(seen, false, sizeof(seen));
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < MAX; i++) graph[i].clear();
}

void bfs() {
    set<int> ans;
    int s;
    while(!q.empty()) {
        ii node = q.front(); q.pop();
        seen[node.first] = true;
        ans.insert(node.first);
        s = node.second;
        for(int i = 0; i < graph[node.first].size(); i++) {
            int x = graph[node.first][i];
            if(!seen[x]) {
                counter[x]++;
                if(counter[x] >= 3) {
                    seen[x] = true;
                    q.push(ii(x, node.second + 1));
                }
            }
        }
    }
    if(ans.size() == N) printf("WAKE UP IN, %d, YEARS\n", s);
    else printf("THIS BRAIN NEVER WAKES UP\n");

}




int main() {
    while(scanf("%d", &N) > 0) {
        init();
        scanf("%d", &M);
        for(int i = 0; i < 3; i++) scanf(" %c", &aux), q.push(ii(aux, 0));
        for(int i = 0; i < M; i++) {
            scanf(" %c %c", &aux, &aux2);
            graph[aux].PB(aux2);
            graph[aux2].PB(aux);
        }
        bfs();
    }
}
