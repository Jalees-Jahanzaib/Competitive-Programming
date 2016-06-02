/* USER: 308958 (osdajigu) */
/* PROBLEM: 865 (924 - Spreading The News) */
/* SUBMISSION: 14249060 */
/* SUBMISSION TIME: 2014-09-23 05:16:33 */
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
#define MAX 2500 + 2
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
vector<int> graph[MAX];
int employees, aux, T, maxDay = 0, maxFriends = 0, source, friends;
bool visited[MAX];
bool informed[MAX];

int days[MAX];

struct myNode {
    int node;
    int day;
    myNode() {}
    myNode(int node, int day) {
        this -> node = node;
        this -> day = day;
    }
};

void solve() {
    queue<myNode> q;
    q.push(myNode(source, 0));
    informed[source] = true;
    while(!q.empty()) {
        myNode n = q.front();
        q.pop();
        if(visited[n.node])
            continue;
        visited[n.node] = true;
        for(int i = 0; i < graph[n.node].size(); i++) {
            if(informed[graph[n.node][i]])
                continue;
            informed[graph[n.node][i]] = true;
            days[n.day + 1]++;
            q.push(myNode(graph[n.node][i], n.day + 1));
        }
    }
    maxFriends = 0;
    maxDay = 0;
    for(int i = 0; i < employees; i++) {
        if(maxFriends < days[i]) {
            maxFriends = days[i];
            maxDay = i;
        }
    }
    if(maxFriends == 0)
        cout << 0 << endl;
    else
        cout << maxFriends << " " << maxDay << endl;

}

int main() {
    cin >> employees;
    for(int i = 0; i < employees; i++) {
        cin >> friends;
        for(int j = 0; j < friends; j++) {
            cin >> aux;
            graph[i].PB(aux);
        }
    }

    cin >> T;
    while(T--) {
        memset(visited, false, sizeof(visited));
        memset(informed, false, sizeof(informed));
        memset(days, false, sizeof(days));
        cin >> source;
        solve();
    }



}
