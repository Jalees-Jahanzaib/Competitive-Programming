#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e4 + 10)
#define INF INT_MAX / 4
#define ll long long
#define LEFT 1
#define RIGHT 2
#define gauss(x) (x)*(x+1)/2

using namespace std;

vector< vector<ii> > G;
int R, C, Q, label, id, disc[MAX], seen[MAX], low[MAX];
int father[MAX], range[MAX];

int find(int x) {
    return father[x] = (x == father[x] ? x : find(father[x]));
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(range[x] > range[y])
        father[y] = x;
    else{
        father[x] = y;
        if(range[x] == range[y])
            range[y]++;
    }
}

void bridges(int cur, int p) {
    disc[cur] = low[cur] = ++id;
    seen[cur] = label;

    for(int i = 0; i < G[cur].size(); i++) {
        int next = G[cur][i].first;
        int edge = G[cur][i].second;
        if(seen[next] != label) {
            bridges(next, cur);
            low[cur] = min(low[cur], low[next]);

            if(low[next] > disc[cur])
                merge(cur, next); /// Es un bridge
        }
        else if(next != p)
            low[cur] = min(low[cur], disc[next]);

    }
}

int main () {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(scanf("%d%d%d", &R, &C, &Q) > 0 && (R + C + Q != 0)) {
        G = vector< vector<ii> > (R + 10);
        label++;

        for(int i = 0; i <= R; i++) {
            father[i] = i;
            range[i] = 0;
        }

        int from, to;
        for(int i = 0; i < C; i++) {
            scanf("%d%d", &from, &to);
            G[from].PB(ii(to, i));
            G[to].PB(ii(from, i));
        }

        id = 0;
        for(int i = 1; i <= R; i++)
            if(seen[i] != label)
                bridges(i, -1);

        while(Q--) {
            scanf("%d%d", &from, &to);
            if(find(from) == find(to)) printf("Y\n");
            else printf("N\n");
        }

        printf("-\n");
    }

}
