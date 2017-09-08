#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 1e3 + 10;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

int n, m, f[MAX];

int find(int x) {
    return f[x] = f[x] == x ? x : find(f[x]);
}

void merge(int a, int b) {
    f[ find(a) ] = find(b);
}

void init(int n) {
    for(int i = 0; i <= n; i++) {
        f[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    while(cin >> n >> m) {
        vector<iii> edges(m);
        init(n);
        for(int i = 0; i < m; i++) {
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        }

        sort(edges.begin(), edges.end());
        int ans = 0, connected = 0;
        for(int i = 0; i < m; i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int c = edges[i].first;
            if(find(u) == find(v)) continue;
            connected++;
            merge(u, v);
            ans += c;
        }

        if(ans != 0 && connected == n-1) cout << ans << "\n";
        else cout << "impossivel\n";
    }
}
