#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int T;
vector< vector<int> > G;
bool first[MAX], seen[MAX], ans[MAX][MAX];

void dfs1(int u) {
    first[u] = true;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!first[v])
            dfs1(v);
    }
}

void dfs2(int u, int p) {
    if(u == p) return;
    seen[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!seen[v])
            dfs2(v, p);
    }
}

int cases, n;
int main() {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    cin >> T;

    while(T--) {
        cin >> n;

        G = vector< vector<int> > (n + 1);
        int x;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                cin >> x;
                if(x == 1) G[i].PB(j);
            }

        memset(first, false, sizeof first);
        dfs1(0);

        memset(ans, false, sizeof ans);
        for(int i = 0; i < n; i++) {
            memset(seen, false, sizeof seen);
            dfs2(0, i);
            for(int j = 0; j < n; j++)
                if(first[j] && !seen[j])
                    ans[i][j] = true;
        }

        cout << "Case " << ++cases << ":\n";
        for(int i = 0; i < n; i++) {
            cout << "+" << string(2*n-1, '-') << "+\n";
            for(int j = 0; j < n; j++) {
                cout << "|"; cout << (ans[i][j] ? "Y" : "N");
            }
            cout << "|\n";
        }
        cout << "+" << string(2*n-1, '-') << "+\n";


    }



}
