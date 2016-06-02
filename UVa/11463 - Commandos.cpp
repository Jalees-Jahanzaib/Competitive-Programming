/* USER: 308958 (osdajigu) */
/* PROBLEM: 2458 (11463 - Commandos) */
/* SUBMISSION: 15070586 */
/* SUBMISSION TIME: 2015-03-02 23:39:12 */
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
#define ii pair<int, int>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 100 + 10
#define LIMIT 1000000
#define MOD 1000000000

int nTest, N, R, from, to, minDist[MAX], cases, visited[MAX];
vector<int> graph[MAX];

void init() {
    for(int i = 0; i < MAX; i++) {
        graph[i].clear();
        minDist[i] = 0;
        visited[i] = 0;
    }
}

void bfs() {
    queue<ii> q;
    q.push(ii(from, 0));
    visited[from] = -1;
    while(!q.empty()) {
        ii p = q.front(); q.pop();
        minDist[p.first] = p.second;
        for(int i = 0; i < graph[p.first].size(); i++)
            if(visited[graph[p.first][i]] != -1) {
                visited[graph[p.first][i]] = -1;
                q.push(ii(graph[p.first][i], p.second + 1));
            }
    }
}

int bfs2(int start, int label) {
    queue<ii> q;
    q.push(ii(start, 0));
    visited[start] = label;
    while(!q.empty()) {
        ii p = q.front(); q.pop();
        if(p.first == to) return p.second;
        for(int i = 0; i < graph[p.first].size(); i++)
            if(visited[graph[p.first][i]] != label) {
                visited[graph[p.first][i]] = label;
                q.push(ii(graph[p.first][i], p.second + 1));
            }
    }
}

int main() {
    scanf("%d", &nTest);
    while(nTest--) {
        init();
        scanf("%d %d", &N, &R);
        for(int i = 0; i < R; i++) {
            scanf("%d %d", &from, &to);
            graph[from].PB(to);
            graph[to].PB(from);
        }
        scanf("%d %d", &from, &to);
        bfs();
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if(from == i) continue;
            ans = max(bfs2(i, i) + minDist[i], ans);
        }
        printf("Case %d: %d\n", ++cases, ans);

    }
}
