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
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 750 + 10
#define INF 0xffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

struct Edge {
    int from, to, cost;
    Edge() {}
    Edge(int from, int to, int cost) : from(from), cost(cost), to(to) {}
    bool operator <(const Edge &e) const {
        return cost < e.cost;
    }
};

vector<Edge> edges;
vector<ii> nodes;
int father[MAX], range[MAX], x, y, n, e, nTest;

void init() {
    edges.clear();
    nodes.clear();
    for(int i = 0; i <= n; i++) {
        father[i] = i;
        range[i] = 0;
    }
}

int find(int x) {
    return father[x] = (father[x] == x ? x : find(father[x]));
}

void merge(int x, int y) {
    int X = find(x);
    int Y = find(y);

    if(range[X] > range[Y])
        father[Y] = X;
    else {
        father[X] = Y;
        if(range[X] == range[Y])
            range[Y]++;
    }
}

void kruskal() {
    sort(edges.begin(), edges.end());

    bool flag = false;
    for(int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if(find(e.from) != find(e.to)) {
            flag = true;
            merge(e.from, e.to);
            cout << e.from + 1 << " " << e.to + 1 << "\n";
        }
    }

    if(!flag)
        cout << "No new highways need\n";
}

inline int dist(ii a, ii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second ) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> nTest;

    bool first = true;
    while(nTest--) {
        if(first) first = !first;
        else cout << "\n";

        cin >> n;
        init();

        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            for(int i = 0; i < nodes.size(); i++)
                edges.PB(Edge(i, nodes.size(), dist(nodes[i], ii(x, y))));
            nodes.PB(ii(x, y));
        }

        cin >> e;
        while(e--) {
            cin >> x >> y;
            x--; y--;
            merge(x, y);
        }

        kruskal();
    }

}
