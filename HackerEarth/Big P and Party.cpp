#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 200;
const double EPS = 1e-5;
const int INF = INT_MAX/2;
const ll MOD = 1000000007;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

const int consuption[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
     ios_base::sync_with_stdio(0);
//     cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans(n+1, -1);
    queue<int> q;
    q.push(0); q.push(0);
    ans[0] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        int l = q.front(); q.pop();

        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(ans[v] == -1) {
                ans[v] = l+1;
                q.push(v);
                q.push(l+1);
            }
        }
    }

    for(int i = 1; i < n; i++) {
        cout << ans[i] << "\n";
    }
    cout << "\n";


}
