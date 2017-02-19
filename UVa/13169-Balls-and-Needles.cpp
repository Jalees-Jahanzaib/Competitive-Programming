#include <bits/stdc++.h>
#define pb      push_back
#define show(x) cout << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef double lf;
typedef complex<lf> pt;
typedef vector<set<int>> graph;

const int MAX = 100005;
bool seen[MAX];

bool check (graph &g, int u, int p) {
    seen[u] = true;
    for (auto v : g[u]) {
        if (!seen[v]) {
            if (!check(g, v, u))
                return false;
        } else if (v != p && v != u)
            return false;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int k;
    int a, b, c, d, e, f;

    while (cin >> k) {
        map<pair<int, int>, int> id1;
        map<pair<pair<int, int>, int>, int> id2;

        graph g1(2 * k), g2(2 * k);
        int u, v;

        int total1 = 0, total2 = 0;
        for (int i = 0; i < k; ++i) {
            cin >> a >> b >> c >> d >> e >> f;

            pair<int, int> x = {a, b};
            pair<int, int> y = {d, e};
            if (!id1.count(x)) id1[x] = u = total1++;
            else u = id1[x];

            if (!id1.count(y)) id1[y] = v = total1++;
            else v = id1[y];

            if (u != v) {
                g1[u].insert(v);
                g1[v].insert(u);
            }

            pair<pair<int, int>, int> w = {x, c};
            pair<pair<int, int>, int> z = {y, f};
            if (!id2.count(w)) id2[w] = u = total2++;
            else u = id2[w];

            if (!id2.count(z)) id2[z] = v = total2++;
            else v = id2[z];

            if (u != v) {
                g2[u].insert(v);
                g2[v].insert(u);
            }
        }

        memset(seen, 0, sizeof seen);
        bool ok1 = true;
        for (int i = 0; i < total1; ++i)
            if (!seen[i])
                ok1 &= check(g1, i, -1);

        memset(seen, 0, sizeof seen);
        bool ok2 = true;
        for (int i = 0; i < total2; ++i)
            if (!seen[i])
                ok2 &= check(g2, i, -1);

        cout << (ok2 ? "No true closed chains" : "True closed chains") << '\n';
        cout << (ok1 ? "No floor closed chains" : "Floor closed chains" ) << '\n';
    }
}
