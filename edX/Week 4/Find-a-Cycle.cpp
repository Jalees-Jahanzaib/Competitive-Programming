#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 100010;

vector< vector<int> > G;
stack<int> st;
bool seen[MAX], processing[MAX];
vector<int> ans;
int times;

bool go(int u) {
    st.push(u);
    processing[u] = true;
    seen[u] = true;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!seen[v] && go(v)) return true;
        else if(processing[v]) {
            ans.push_back(v);
            while(st.top() != v) {
                ans.push_back(st.top());
                st.pop();
            }
            return true;
        }
    }

    st.pop();
    processing[u] = false;

    return false;
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);

    int n, m; scanf("%d %d", &n, &m);
    G = vector< vector<int> > (n+1);
    for(int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }

    for(int i = 1; i <= n; i++) {
        if(!seen[i])
            if(go(i))
                break;
    }

    reverse(ans.begin(), ans.end());
    if(ans.size() > 0) {
        printf("YES\n");
        for(int i = 0; i < ans.size(); i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }



}
