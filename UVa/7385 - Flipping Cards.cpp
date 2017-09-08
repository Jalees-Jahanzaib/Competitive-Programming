#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

struct Hopcroft_Karp {
    int n1, n2, edges;
    vi last, prev, head, matching, dist, q;
    vb used, vis;

    Hopcroft_Karp(int max_n1, int max_n2, int max_m) :
        last(max_n1), prev(max_m), head(max_m),
        matching (max_n2), dist(max_n1), q(max_n1),
        used(max_n1), vis(max_n1) {
        }

    void init(int n1, int n2) {
        this->n1 = n1;
        this->n2 = n2;
        edges = 0;
        fill(last.begin(), last.begin()+n1, -1);;
    }
    /// u -> 0 to n1, v -> 0 to n2
    void add_edge(int u, int v) {
        head[edges] = v;
        prev[edges] = last[u];
        last[u] = edges++;
    }

    void bfs() {
        fill(dist.begin(), dist.begin()+n1, -1);
        int size_q = 0;
        for(int u = 0; u < n1; u++) {
            if(!used[u]) {
                q[size_q++] = u;
                dist[u] = 0;
            }
        }

        for(int i = 0; i < size_q; i++) {
            int u1 = q[i];
            for(int e = last[u1]; e >= 0; e = prev[e]) {
                int u2 = matching[ head[e] ];
                if(u2 >= 0 && dist[u2] < 0) {
                    dist[u2] = dist[u1]+1;
                    q[ size_q++ ] = u2;
                }
            }
        }
    }

    bool dfs(int u1) {
        vis[u1] = true;
        for(int e = last[u1]; e >= 0; e = prev[e]) {
            int v = head[e];
            int u2 = matching[v];
            if(u2 < 0 || ( !vis[u2] && dist[u2] == dist[u1]+1 && dfs(u2) )) {
                matching[ v ] = u1;
                used[u1] = true;
                return true;
            }
        }
        return false;
    }

    int max_matching() {
        fill(used.begin(), used.begin()+n1, false);
        fill(matching.begin(), matching.begin()+n2, -1);
        int ans = 0;
        while(true) {
            bfs();
            fill(vis.begin(), vis.begin()+n1, false);
            int f = 0;
            for(int u = 0; u < n1; u++) {
                if(!used[u] && dfs(u)) {
                    f++;
                }
            }
            if(f == 0) {
                return ans;
            }
            ans += f;
        }
        return 0;
    }


};

int main() {
    ios_base::sync_with_stdio(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ii> cards(n);
        int max_n1 = n, max_n2 = -1;
        for(int i = 0; i < n; i++) {
            cin >> cards[i].first >> cards[i].second;
            max_n2 = max(max_n2, cards[i].first);
            max_n2 = max(max_n2, cards[i].second);
        }

        Hopcroft_Karp net(max_n1+10, max_n2+10, 2*max_n1 + 10);
        net.init(max_n1+10, max_n2+10);

        for(int i = 0; i < n; i++) {
            net.add_edge(i, cards[i].first);
            net.add_edge(i, cards[i].second);
        }

        int ans = net.max_matching();

        if(ans == n) cout << "possible\n";
        else cout << "impossible\n";


    }

}

