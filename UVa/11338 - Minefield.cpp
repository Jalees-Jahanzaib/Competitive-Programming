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
#define dd pair<double, double>
#define ii pair<double, int>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 10000 + 10
#define INF INT_MAX / 5
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

vector<dd> nodes;
double minDist, d[MAX];
int w, h, n;
vector<int> G[MAX];

void init() {
    nodes.clear();
    for(int i = 0; i <= n + 3; i++) {
        G[i].clear();
        d[i] = INF;
    }
}

double getDist(dd a, dd b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool can(dd a, dd b) {
    return 1.5 >= sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, 0));
    d[0] = 0.0;
    while(!q.empty()) {
        int node = q.top().second;
        double dist = q.top().first;
        q.pop();
        if(d[node] < dist) continue;
        for(int i = 0; i < G[node].size(); i++) {
            int next = G[node][i];
            double ndist = dist + getDist(nodes[node], nodes[next]);
            if(d[next] > ndist) {
                q.push(ii(ndist, next));
                d[next] = ndist;
            }
        }
    }

    return minDist >= d[n + 1];

}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.txt", "r", stdin);
    string line;

    while(cin >> line && line != "*") {
        sscanf(line.c_str(), "%d", &w);
        scanf("%d%d", &h, &n);

        init();

        double x, y;
        nodes.PB(dd(0,0));
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf", &x, &y);
            nodes.PB(dd(x, y));
            for(int j = 0; j < i; j++)
                if(can(nodes[i], nodes[j])) {
                    G[j].PB(i);
                    G[i].PB(j);
                }
        }

        nodes.PB(dd(w, h));
        for(int j = 0; j <= n; j++)
            if(can(nodes[n + 1], nodes[j])) {
                G[j].PB(n + 1);
                G[n + 1].PB(j);
            }

        scanf("%lf", &minDist);

        if(dijkstra()) printf("I am lucky!\n");
        else printf("Boom!\n");
    }
}
