#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 500 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

vector< vector<int> > G;
vector<bool> seen;
stack<int> s;
int n, m, a, b;

void dfs(int u) {
    seen[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!seen[v])
            dfs(v);
    }
    s.push(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    while(cin >> n >> m &&(n + m) != 0) {
        G = vector< vector<int> >(n + 2);
        seen = vector<bool>(n + 2, false);

        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            G[a].PB(b);
        }

        for(int i = 1; i <= n; i++) {
            if(!seen[i])
                dfs(i);
        }
        bool f = true;
        while(!s.empty()) {
            if(f) f = false;
            else cout << " ";
            cout << s.top();
            s.pop();
        }
        cout << "\n";
    }

}
