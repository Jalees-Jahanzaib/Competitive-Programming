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
#define MAX 100 + 10

using namespace std;

int n, m, father[MAX][MAX], from, to, color;

void init() {
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            father[i][j] = i;
}

int find(int x, int c) {
    if(x == father[x][c]) return x;
    return father[x][c] = find(father[x][c], c);
}

void merge() {
    father[find(from, color)][color] = find(to, color);
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &from, &to, &color);
        if(find(from, color) != find(to, color))
            merge();
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int ans = 0;
        scanf("%d%d", &from, &to);
        for(int j = 0; j <= m; j++)
            if(find(from, j) == find(to, j)) ans++;
        printf("%d\n", ans);
    }

}
