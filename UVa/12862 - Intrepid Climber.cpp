#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e5 + 10)
#define INF INT_MIN / 5;

using namespace std;

int n, f, d[MAX], worst, all;
vector<vector<ii> > G;
bool friends[MAX];


bool dfs(int node, int dist) {
    bool flag = false;
    if(friends[node]) {
        worst = max(worst, dist);
        flag = true;
    }

    for(int i = 0; i < G[node].size(); i++) {
        int next = G[node][i].first;
        if(dfs(next, dist + G[node][i].second)) {
            all += G[node][i].second;
            flag = true;
        }
    }

    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n >> f) {
        G = vector<vector<ii> >(n);

        int from, to, cost;

        for(int i = 0; i < n - 1; i++) {
            cin >> from >> to >> cost;
            from--; to--;
            G[from].PB(ii(to, cost));
            friends[to] = false;
            friends[from] = false;
        }

        worst = -1;

        int fr;
        for(int i = 0; i < f; i++) {
            cin >> fr;
            fr--;
            friends[fr] = true;
        }

        all = 0;
        worst = -1;
        dfs(0, 0);

        cout << all - worst << "\n";

    }
}
