#include<iostream>
#include<algorithm>
#define MAX 10000 + 5

using namespace std;

struct Edge {
    int from, to, cost;
    bool operator<(const Edge& e) const {
        return cost > e.cost;
    }
};

Edge edges[MAX], MST[MAX];
int V, E, nTest, cases = 1, ans;
int father[MAX], height[MAX];

void initializate() {
    for(int i = 0; i < V; i++) {
        father[i] = i;
        height[i] = 0;
    }
}

int find(int x) {
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

///                from     to
void unionByHeight(int x, int y) {
    int xFather = find(x);
    int yFather = find(y);
    if(height[xFather] > height[yFather]) father[yFather] = xFather;
    else {
        father[xFather] = yFather;
        if(height[xFather] == height[yFather]) height[yFather]++;
    }
}

void Kruskal() {
    initializate();
    sort(edges, edges + E);
    for(int i = 0; i < E; i++)
        if(find(edges[i].from) != find(edges[i].to)) {
            unionByHeight(edges[i].from, edges[i].to);
            ans = edges[i].cost;
        }
    cout <<"Case #" << cases++ << ": " << ans << endl;
}


int main() {
    cin >> nTest;
    while(nTest--) {
        cin >> V >> E;
        for(int i = 0; i < E; i++)
            cin >> edges[i].from >> edges[i].to >> edges[i].cost;

        Kruskal();
    }
}
