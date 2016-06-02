#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100000 + 20
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int degree[MAX], v[MAX], n, nodes;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    string line;
    bool first = true;
    while(getline(cin, line)) {
        if(first) first = false;
        else cout << "*\n";

        memset(degree, 0, sizeof(degree));
        istringstream ss(line);
        n = 0, nodes = 0;
        while(ss >> v[n]) {
            degree[v[n]]++;
            n++;
        }

        nodes = n + 1;
        vector< vector<int> > G(MAX);

        priority_queue<int> q;
        for(int i = 0; i <= nodes; i++)
            if(!degree[i])
                q.push(-i);


        int idx = -1;
        while(!q.empty() && idx < n - 1) {
            int cur = -q.top(); q.pop();
            idx++;
            G[cur].PB(v[idx]);
            G[v[idx]].PB(cur);
            degree[v[idx]]--;
            if(degree[v[idx]] == 0)
                q.push(-v[idx]);
        }
        if(q.size() >= 2) {
            int f = -q.top(); q.pop();
            int t = -q.top(); q.pop();
            G[f].PB(t);
            G[t].PB(f);
        }

        bool ok = true;
        int edges = 0;
        for(int i = 0; i <= nodes; i++) {
            ok &= G[i].size() > 0;
            edges += G[i].size();
        }

        if(ok && edges % 2 == 0 && (edges / 2) == nodes) {
            cout << nodes + 1 << "\n";
            for(int i = 0; i <= nodes; i++) {
                sort(G[i].begin(), G[i].end());
                for(int j = 0; j < G[i].size(); j++) {
                    if(j) cout << " ";
                    cout << G[i][j];
                }
                cout << "\n";
            }
        }
        else
            cout << "impossible\n";

    }
}
