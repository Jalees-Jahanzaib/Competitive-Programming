#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAX = 2010;

int idx[MAX], low[MAX], tag[MAX];
bool in_stack[MAX];
vector<vector<int> > G, NG;
int label;

int SCC ( int &index, int u, stack<int> &st ) {
    idx[u] = low[u] = ++index;
    st.push(u);
    in_stack[u] = true;
    for ( int i = 0; i < G[u].size(); ++i ) {
        int v = G[u][i];
        if ( idx[v] == -1 ) {
            SCC(index, v, st);
            low[u] = min(low[u], low[v]);
        } else if ( in_stack[v] )
            low[u] = min(low[u], idx[v]);
    }
    if ( low[u] == idx[u] ) {
        label++;
        while ( true ) {
            int v = st.top(); st.pop();
            tag[v] = label;
            in_stack[v] = false;
            if ( v == u ) break;
        }
    }
}

int cnt;
void dfs(int u, vector<bool> &seen) {
    seen[u] = true;
    cnt++;
    for(int i = 0; i < NG[u].size(); i++) {
        int v = NG[u][i];
        if(!seen[v]) {
            dfs(v, seen);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(idx, -1, sizeof idx);
    int n; cin >> n;
    G = vector<vector<int>> (n+1);
    for(int i = 1; i <= n; i++) {
        int x;
        while(cin >> x && x != 0) {
            G[i].push_back(x);
        }
    }
    int index = 0;
    stack<int> st;
    for(int i = 1; i <= n; i++) {
        if(idx[i] == -1) {
            SCC(index, i, st);
        }
    }
    NG = vector<vector<int>> (label+1);
    vector<int> degree(label+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < G[i].size(); j++) {
            if(tag[i] != tag[ G[i][j] ]) {
                NG[ tag[i] ].push_back( tag[ G[i][j] ]);
                degree[ tag[ G[i][j] ] ]++;
            }
        }
    }
    vector<bool> seen(label+1);
    for(int i = 1; i <= label; i++) {
        if(degree[i] == 0) {
            cnt = 0;
            dfs(i, seen);
            if(cnt == label) {
                for(int k = 1; k <= n; k++) {
                    if(tag[k] == i) {
                        cout << k << " ";
                    }
                }
            }
            break;
        }
    }

    cout << 0 << "\n";
}
