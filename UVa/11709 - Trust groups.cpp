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
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] != '#'
#define MAX 1000 + 10
#define INF 0xfffffff
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

struct Node {
    int index, lowlink;
    bool onStack;
    vector<Node*> neighbor;

    Node () {
        index = -1;
        onStack = false;
    }
};

map<string, int> id;
vector<Node> G;
stack<Node*> S;
int P, T, ind, ans;
string name, from, to;

void dfs(Node *u) {
    u->index = ind;
    u->lowlink = ind;
    ind++;

    S.push(u);
    u->onStack = true;

    for(int i = 0; i < u->neighbor.size(); i++) {
        Node *v = u->neighbor[i];
        if(v->index == -1) {
            dfs(v);
            u->lowlink = min(u->lowlink, v->lowlink);
        }
        else if(v->onStack)
            u->lowlink = min(u->lowlink, v->index);
    }

    if(u->lowlink == u->index) {
        while(!S.empty()) {
            Node *cur = S.top(); S.pop();
            cur->onStack = false;
            if(u->index == cur->index)
                break;
        }
        ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> P >> T && (P != 0 || T != 0)) {
        ind = 0;
        G = vector<Node>(P);
        while(!S.empty()) S.pop();
        id.clear();

        getline(cin, name);
        for(int i = 0; i < P; i++) {
            getline(cin, name);
            id[name] = i;
        }

        for(int i = 0; i < T; i++) {
            getline(cin, from);
            getline(cin, to);
            G[id[from]].neighbor.PB(&G[id[to]]);
        }

        ans = 0;
        for(int i = 0; i < P; i++) {
            if(G[i].index == -1)
                dfs(&G[i]);
        }

        cout << ans << "\n";
    }
}

