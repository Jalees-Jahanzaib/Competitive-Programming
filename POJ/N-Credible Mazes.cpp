//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 3162280;
const double EPS = 1e-5;
const int INF = INT_MAX;

map<ll, ll> id;
int tag, n;

void get(string &line, ll &a, ll &b) {
    stringstream ss(line);
    for(int i = 0; i < n; i++) {
        int x; ss >> x;
        a = a*10ll + x;
    }
    for(int i = 0; i < n; i++) {
        int x; ss >> x;
        b = b*10ll + x;
    }
    if(!id.count(a)) id[a] = tag++;
    if(!id.count(b)) id[b] = tag++;

    a = id[a]; b = id[b];
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    while(cin >> n && n) {

        cin.ignore();
        string line; getline(cin, line);
        tag = 0;

        id.clear();

        ll s = 0, f = 0;
        get(line, s, f);

        vector<ii> edges;
        int lim = 0;

        while(getline(cin, line) && line != "-1") {
            ll a = 0, b = 0;
            get(line, a, b);
            lim = max(lim, int(a));
            lim = max(lim, int(b));
            edges.push_back(ii(a, b));
        }

        vector< vector<int> > G(lim+1);
        for(int i = 0; i < edges.size(); i++) {
            G[ edges[i].first ].push_back(edges[i].second);
            G[ edges[i].second].push_back(edges[i].first);
        }
        bool ok = false;
        queue<int> q;
        q.push(s);
        vector<bool> seen(lim+1);
        seen[s] = true;
        while(q.size()) {
            int u = q.front(); q.pop();

            if(u == f) {
                ok = true;
                break;
            }

            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if(!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
            }
        }

        if(ok) cout << "Maze #" << ++cases << " can be travelled\n";
        else cout << "Maze #" << ++cases << " cannot be travelled\n";
    }

}
