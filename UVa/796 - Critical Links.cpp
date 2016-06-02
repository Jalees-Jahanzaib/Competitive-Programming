#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 500 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

set<ii> ans;
vector< vector<int> > G;
int id;
void bridges(int cur, int p, vector<int> &disc, vector<int> &low, vector<bool> &seen) {
    disc[cur] = low[cur] = ++id;
    seen[cur] = true;

    for(int i = 0; i < G[cur].size(); i++) {
        int next = G[cur][i];
        if(!seen[next]) {
            bridges(next, cur, disc, low, seen);
            low[cur] = min(low[cur], low[next]);

            if(low[next] > disc[cur])
                ans.insert(ii(min(cur, next), max(cur, next)));
        }
        else if(next != p)
            low[cur] = min(low[cur], disc[next]);
    }
}

int n, t, from;

int main() {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);
    cout.tie(0);/**/
    while(cin >> n) {
        G = vector< vector<int> >(n + 2);
        ans.clear();
        char g;
        for(int i = 0; i < n; i++) {
            cin >> from;
            cin >> g >> t >> g;
            int x;
            for(int j = 0; j < t; j++) {
                cin >> x;
                G[from].PB(x);
            }
        }

        vector<int> disc(n + 2, 0), low(n + 2, 0);
        vector<bool> seen(n + 2, false);

        id = 0;
        for(int i = 0; i < n; i++)
            if(!seen[i])
                bridges(i, -1, disc, low, seen);
        cout << ans.size() << " critical links\n";
        for(auto &x : ans) {
            cout << x.first << " - " << x.second << "\n";
        }
        cout << "\n";

    }


}
