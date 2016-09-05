#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 500
#define INF INT_MAX / 3
#define ll long long

using namespace std;

struct State {
    int node, cost, time, steps;
    State(int node, int cost, int time, int steps) : node(node), cost(cost), time(time), steps(steps) {}

    bool operator < (const State &a) const {
        if(cost != a.cost) return cost < a.cost;
        if(time != a.time) return time < a.time;
        return steps < a.steps;
    }
};

struct Node {
    int to, cost, time;
    Node(int to, int cost, int time) : to(to), cost(cost), time(time) {}
};

int p, f, q;
ii dp[MAX][MAX];
map<string, int> id;
vector< vector<Node> > G;

void bellman(int from, int n) {
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dp[i][j] = ii(INF, INF);

    for(int i = 0; i < n; i++) dp[i][from] = ii(0, 0);

    /// [steps][nodo]
    for(int i = 1; i <= p; i++) ///step´s
        for(int u = 0; u < p; u++) {
            for(int k = 0; k < G[u].size(); k++) {
                Node v = G[u][k];
                if(dp[i][v.to].first > dp[i - 1][u].first + v.cost) {
                    dp[i][v.to].first = dp[i - 1][u].first + v.cost;
                    dp[i][v.to].second = dp[i - 1][u].second + v.time;
                }
                else if(dp[i][v.to].first == dp[i - 1][u].first + v.cost && dp[i][v.to].second > dp[i - 1][u].second + v.time) {
                    dp[i][v.to].second = dp[i - 1][u].second + v.time;
                }
            }
        }

}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)
    bool first = true;
    while(cin >> p >> f >> q) {
        if(first) first = false;
        else cout << ".\n";

        id.clear();
        G = vector< vector<Node> >(p + 1);

        string name;
        for(int i = 0; i < p; i++) {
            cin >> name;
            id[name] = i;
        }

        string from, to;
        int cost, time;
        for(int i = 0; i < f; i++) {
            cin >> from >> to >> cost >> time;
            G[id[from]].PB(Node(id[to], cost, time));
        }

        cin >> from;
        bellman(id[from], p + 2);

        int n;
        for(int i = 0; i < q; i++) {
            cin >> to >> n;
            ii ans = ii(INF, INF);
            for(int i = 1; i <= n + 1; i++)
                ans = min(ans, dp[i][id[to]]);

            if(ans.first != INF) cout << ans.first << " " << ans.second << "\n";
            else cout << "* *\n";
        }
    }

}
