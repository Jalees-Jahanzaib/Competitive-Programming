/* USER: 308958 (osdajigu) */
/* PROBLEM: 985 (10044 - Erdos Numbers) */
/* SUBMISSION: 14254467 */
/* SUBMISSION TIME: 2014-09-24 04:18:58 */
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

int scenarios, P, N, cont = 0;
string s, aux;
map<string, vector<string> > graph;
vector<string> temp;
map<string, bool > visited;
map<string, int > ans;

struct myNode {
    string node;
    int cost;
    myNode() {}

    myNode(string node, int cost) {
        this -> node = node;
        this -> cost = cost;
    }

};

void solve() {
    queue<myNode> q;
    q.push(myNode("Erdos, P.", 0));
    while(!q.empty()) {
        myNode n = q.front();
        q.pop();
        if(visited[n.node])
            continue;
        visited[n.node] = true;
        ans[n.node] = n.cost;
        for(int i = 0; i < graph[n.node].size(); i++) {
            q.push(myNode(graph[n.node][i], n.cost + 1));
        }
    }
}

void initializate() {
    graph.clear();
    visited.clear();
    ans.clear();
}

int main() {
    cin >> scenarios;
    int auxS = 1;
    while(scenarios--) {
        initializate();
        cin >> P >> N;
        cin.ignore();
        for(int i = 0; i < P; i++) {
            getline(cin, s);
            aux = "";
            cont = 0;
            temp.clear();
            for(int i = 0; i < s.size(); i++) {
                //cout << cont << "->"<< s[i] <<  endl;
                if(s[i] == ',' || s[i] == ':')
                    cont++;
                if(cont < 2)
                    aux += s[i];
                if(cont == 2) {
                    temp.PB(aux);
                    aux = "";
                    cont = 0;
                    i++;
                }
                if(s[i] == ':')
                    break;
            }
            for(int i = 0; i < temp.size(); i++) {
                for(int j = 0; j < temp.size(); j++) {
                    graph[temp[i]].PB(temp[j]);
                    //cout << temp[i] << "->" << temp[j] << endl;
                }
            }
        }

        solve();
        cout << "Scenario " << auxS++ << endl;
        for(int i = 0; i < N; i++) {
            getline(cin, s);
            cout << s;
            if(ans[s] == 0)
                cout << " infinity" << endl;
            else
                cout << " " << ans[s] << endl;

        }
    }
}
