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
#define ii pair<double, int>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 100 + 10
#define INF INT_MAX / 5
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

struct Node {
    int cur, p;
    double temp, cost;
    Node() {}
    Node(int cur, double temp, double cost, int p = -1) : cur(cur), cost(cost), temp(temp), p(p) {}
};

int n, e, start, finish, from, P[MAX];
double d[MAX], t[MAX];
vector<Node> G[MAX];

void init() {
    for(int i = 0; i <= n + 2; i++) {
        d[i] = INF;
        t[i] = INF;
        P[i] = -1;
        G[i].clear();
    }
}

void dijkstra1() {
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, start));
    t[start] = 0;
    while(!q.empty()) {
        int node = q.top().second;
        double temp = q.top().first;
        q.pop();

        if(t[node] < temp) continue;

        for(int i = 0; i < G[node].size(); i++) {
            int next = G[node][i].cur;
            if(next == node) continue;
            double ntemp = fmax(temp, G[node][i].temp);

            if(t[next] > ntemp)  {
                t[next] = ntemp;
                q.push(ii(ntemp, next));
            }
        }
    }
}

void dijkstra2(double mt) {
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, start));
    d[start] = 0;
    while(!q.empty()) {
        int node = q.top().second;
        double dist = q.top().first;
        q.pop();

        if(d[node] < dist) continue;

        for(int i = 0; i < G[node].size(); i++) {
            int next = G[node][i].cur;
            if(next == node) continue;
            double ndist = dist + G[node][i].cost;
            double ntemp = G[node][i].temp;

            if(ntemp <= mt && d[next] > ndist) {
                d[next] = ndist;
                q.push(ii(ndist, next));
                P[next] = node;
            }
        }
    }
}

void printPath(int cur) {
    if(P[cur] != -1) printPath(P[cur]), printf(" %d", cur);
    else printf("%d", cur);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    while(scanf("%d%d%d%d", &n, &e, &start, &finish) > 0) {
        init();

        int from, to;
        double cost, temp;
        for(int i = 0; i < e; i++) {
            scanf("%d%d%lf%lf", &from, &to, &temp, &cost);
            G[from].PB(Node(to, temp, cost));
            G[to].PB(Node(from, temp, cost));
        }

        dijkstra1();
        dijkstra2(t[finish]);
        printPath(finish);

        printf("\n%.1f %.1f\n", d[finish], t[finish]);
    }

}
