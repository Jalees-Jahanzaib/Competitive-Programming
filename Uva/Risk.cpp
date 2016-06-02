//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define PB push_back
#define MAX 50
#define check(x, y, z) x >= 0 && y >= 0 && z >= 0 && x < R && y < C && z < L && !seen[x][y][z]

using namespace std;

int N, cases, e, aux, from, to;
int minDist[MAX][MAX];

void init() {
    e = 1;
    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 25; j++) {
            if(i == j) minDist[i][j] = 0;
            else minDist[i][j] = 500;
        }
}

void floyd() {
    for(int k = 1; k <= 20; ++k)
        for(int i = 1; i <= 20; i++)
            for(int j = 1; j <= 20; j++)
                minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
}

int main() {
    while(scanf("%d", &N) > 0) {
        init();
        for(int i = 0; i < N; i++) scanf("%d", &aux), minDist[e][aux] = 1, minDist[aux][e] = 1;
        while(++e <= 19) {
            scanf("%d", &N);
            for(int i = 0; i < N; i++) scanf("%d", &aux), minDist[e][aux] = 1, minDist[aux][e] = 1;
        }
        floyd();
        printf("Test Set #%d\n", ++cases);
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%d%d", &from, &to);
            printf("%2d to %2d: %d\n", from, to, minDist[from][to]);
        }
        printf("\n");
    }
}
