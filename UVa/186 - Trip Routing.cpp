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
#define ii pair<int, char>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 100 + 10
#define INF 0xffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

struct Edge {
    string from, to, name;
    int cost, value;
    Edge(string from = "", string to = "", string name = "", int cost = 0, int value = INF) : from(from), to(to), name(name), cost(cost), value(value) {}
}minDist[MAX][MAX];

string line;
map<string, int> id;
int P[MAX][MAX], n;

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(minDist[i][j].value > minDist[i][k].value + minDist[k][j].value) {
                   minDist[i][j].value = minDist[i][k].value + minDist[k][j].value;
                   P[i][j] = P[k][j];
                }
}

vector<int> path;
void print_path(int u, int v) {
    if(P[u][v] != u) print_path(u, P[u][v]);
    path.PB(v);
}

int main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    freopen("input.txt", "r", stdin);

    memset(P, -1, sizeof(P));

    for(int i = 0; i < MAX; i++)
        if(i == i) minDist[i][i].value = 0;

    n = 1;
    while(getline(cin, line) && line != "") {
        int i = 0, cost = 0;
        string from = "", to = "", name = "";
        while(line[i] != ',') from += line[i], i++;
        i++;
        while(line[i] != ',') to += line[i], i++;
        i++;
        while(line[i] != ',') name += line[i], i++;
        i++;
        while(i < line.size()) cost *= 10, cost += line[i] - '0', i++;

        if(!id.count(from)) id[from] = n, n++;
        if(!id.count(to)) id[to] = n, n++;

        Edge e1 = Edge(from, to, name, cost, cost);
        Edge e2 = Edge(to, from, name, cost, cost);
        int x = id[from], y = id[to];
        if(minDist[x][y].value > e1.value) {
            minDist[x][y] = e1;
            minDist[y][x] = e2;
            P[x][y] = x;
            P[y][x] = y;
        }
    }
    n--;

    floyd();

    while(getline(cin, line) && line != "") {
        path.clear();
        string from = "", to = "";
        int i = 0;
        while(line[i] != ',') from += line[i], i++;
        i++;
        while(i < line.size()) to += line[i], i++;
        int x = id[from], y = id[to];

        printf("\n\nFrom                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");
        path.PB(x);
        print_path(x, y);

        for(int j = 0; j < path.size() - 1; j++)
            printf("%-20s %-20s %-10s %5d\n", minDist[path[j]][path[j + 1]].from.c_str(), minDist[path[j]][path[j + 1]].to.c_str(), minDist[path[j]][path[j + 1]].name.c_str(), minDist[path[j]][path[j + 1]].cost);
        printf("                                                     -----\n");
        printf("                                          Total      %5d\n", minDist[x][y].value);
    }
}
