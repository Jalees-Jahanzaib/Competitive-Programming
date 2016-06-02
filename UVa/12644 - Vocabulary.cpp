#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e2 * 5 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

string s;
int c, v;
vector< vector<int> > G;
bool seen[2*MAX];
int R[2*MAX], L[2*MAX];

bool dfs(int node) {
    if(seen[node]) return false;
    seen[node] = true;
    for(int i = 0; i < G[node].size(); i++) {
        int next = G[node][i];
        if(R[next] == -1 || dfs(R[next])) {
            R[next] = node;
            L[node] = next;
            return true;
        }
    }

    return false;
}

int maxBipartiteMatching() {
    int ans = 0;
    memset(R, -1, sizeof(R));
    memset(L, -1, sizeof(L));
    bool path;
    do {
        path = false;
        memset(seen, false, sizeof(seen));
        for(int i = 0; i < c; i++) {
            if(L[i] == -1 && !seen[i])
                if(dfs(i)) {
                    path = true;
                    ans++;
                }
        }
    }while(path);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> c >> v) {
        G = vector< vector<int> >(c + v);

        vector<string> vocabulary;
        for(int i = 0; i < c; i++) {
            cin >> s;
            sort(s.begin(), s.end());
            vocabulary.PB(s);
        }
        for(int i = 0; i < v; i++) {
            cin >> s;
            sort(s.begin(), s.end());
            for(int j = 0; j < vocabulary.size(); j++) {
                int m = 0, n = 0;
                while(m < s.size() && n < vocabulary[j].size()) {
                    if(s[m] == vocabulary[j][n]) m++, n++;
                    else n++;
                }
                if(m == s.size()) {
                    G[c + i].PB(j);
                    G[j].PB(c + i);
                }
            }
        }

        cout << maxBipartiteMatching() << "\n";

    }
}



