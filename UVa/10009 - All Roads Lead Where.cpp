/* USER: 308958 (osdajigu) */
/* PROBLEM: 950 (10009 - All Roads Lead Where?) */
/* SUBMISSION: 14253696 */
/* SUBMISSION TIME: 2014-09-23 22:10:02 */
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
#include<utility>
#include<sstream>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define PB push_back
#define EPS 0.00000001
#define MAX 26 + 2
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
int m, nTest, tQuerys;
vector<int> graph[MAX];
string c1, c2, root, query;
bool visited[MAX];

struct myNode{
    int node;
    string route;

    myNode() {}
    myNode(int node, string route) {
        this -> node = node;
        this -> route = route;
    }
};

void solve() {
    string aux = "";
    queue<myNode> q;
    q.push(myNode(root[0] - 'A', aux + root[0]));
    while(!q.empty()) {
        myNode n = q.front();
        q.pop();
        if(n.node == (query[0] - 'A')) {
            cout << n.route << endl;
            return;
        }
        if(visited[n.node])
            continue;
        visited[n.node] = true;
        for(int i = 0; i < graph[n.node].size(); i++) {
            q.push(myNode(graph[n.node][i], n.route + (char) (graph[n.node][i] + 'A')));
        }
    }
}

void initializate() {
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
}


int main() {
    cin >> nTest;
    while(nTest--) {
        initializate();
        cin >> m >> tQuerys;
        for(int i = 0; i < m; i++) {
            cin >> c1 >> c2;
            graph[c1[0] - 'A'].PB(c2[0] - 'A');
            graph[c2[0] - 'A'].PB(c1[0] - 'A');
        }
        //while(tQuerys--) {
        for(int i = 0; i < tQuerys; i++) {
            memset(visited, false, sizeof(visited));
            cin >> root >> query;
            solve();
        }
        if(nTest >= 1)
            cout << endl;
    }

}
