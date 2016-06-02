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

#define ll long long
#define ii pair<int, int>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] != '#'
#define MAX MAX
#define INF 0xfffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

int cities[100], cases, C, R, Q, minDist[100][100], prev[100][100], w, from, to, cost[100][100];

int main() {
    bool first = true;

    while(scanf("%d%d%d", &C, &R, &Q) > 0 && C != 0 && R != 0 && C != 0) {
        if(first) first = false;
        else printf("\n");

        for(int i = 1; i <= C; i++)
            for(int j = 1; j <= C; j++) {
                if(i == j) minDist[i][j] = 0;
                else minDist[i][j] = INF;
                prev[i][j] = -1;
                cost[i][j] = 0;
            }

        for(int i = 1; i <= C; i++) scanf("%d", &cities[i]);

        for(int i = 0; i < R; i++) {
            scanf("%d%d%d", &from, &to, &w);
            prev[from][to] = from;
            prev[to][from] = to;
            cost[from][to] = max(cities[from], cities[to]);
            cost[to][from] = max(cities[from], cities[to]);
            cost[from][from] = cities[from];
            cost[to][to] = cities[to];
            minDist[from][to] = minDist[to][from] = w + cost[from][to];
            minDist[to][to] = cities[to];
            minDist[from][from] = cities[from];

        }
        for(int l = 1; l <= 2; l++)
            for(int k = 1; k <= C; k++)
                for(int i = 1; i <= C; i++)
                    for(int j = 1; j <= C; j++) {
                        int i_k_j = minDist[i][k] + minDist[k][j] - cost[i][k] - cost[k][j] + max(cost[i][k], cost[k][j]);
                        if(minDist[i][j] > i_k_j) {
                            minDist[i][j] = i_k_j;
                            cost[i][j] = max(cost[i][k], cost[k][j]);
                            prev[i][j] = prev[k][j];
                        }
                    }

        printf("Case #%d\n", (++cases));
        while(Q--) {
            scanf("%d%d", &from, &to);
            int ans = minDist[from][to];
            if(prev[from][to] == -1) printf("-1\n");
            else printf("%d\n", ans);
        }

    }

}

