#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 500 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

vector< vector<int> > G, RG;
stack<int> s;
vector<bool> seen;

void dfs1(int u) {
    seen[u] = true;
    for(int v : G[u])
        if(!seen[v])
            dfs1(v);
    s.push(u);
}

void dfs2(int u) {
    seen[u] = true;
    for(int v : RG[u]) {
        if(!seen[v])
            dfs2(v);
    }
}

int n, m, a, b, c;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/
    while(cin >> n >> m && (n + m != 0)) {
        G = vector< vector<int> >(n + 2);
        RG = vector< vector<int> >(n + 2);
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            a--;
            b--;
            G[a].PB(b);
            RG[b].PB(a);
            if(c == 2) G[b].PB(a), RG[a].PB(b);
        }

        seen = vector<bool> (n + 2, false);

        for(int i = 0; i < n; i++)
            if(!seen[i])
                dfs1(i);
        int ans = 0;
        seen = vector<bool>(n + 2, false);
        while(!s.empty()) {
            int k = s.top(); s.pop();
            if(!seen[k]) {
                dfs2(k), ans++;
            }
        }
        if(ans == 1) cout << "1\n";
        else cout << "0\n";

    }


}
