#include<bits/stdc++.h>

#define MOD			1000000021LL
#define MAX_N		100000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 100010;
const int INF = INT_MAX/2;
const int MAXLOG = 30;

int height[MAX], l[MAX], r[MAX];
int RMQ[MAX][MAXLOG];

int get(int a, int b) {
    int j = 31 - __builtin_clz(b-a+1);
    return min(RMQ[a][j], RMQ[b-(1<<j)+1][j]);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n) {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            cin >> height[i];
            while(!st.empty() && height[st.top()] <= height[i]) {
                st.pop();
            }
            l[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && height[st.top()] <= height[i]) {
                st.pop();
            }
            r[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }

        for(int i = 0; i < n; i++) RMQ[i][0] = height[i];
        for(int j = 1; (1<<j) <= n; j++) {
            for(int i = 0; i + (1<<j-1) < n; i++) {
                RMQ[i][j] = min( RMQ[i][j-1], RMQ[i + (1<<j-1)][j-1] );
            }
        }

        vector<int> ultras;
        for(int i = 0; i < n; i++) {
            int mleft = -1, mright = -1;
            if(l[i] != -1) mleft = get(l[i], i);
            if(r[i] != -1) mright = get(i, r[i]);
            int d = max(mleft, mright);
            if(d == height[i]) continue;

            if(d == -1) d = height[i];
            else d = height[i]-d;
            if(d >= 150000) ultras.push_back(i);
        }

        for(int i = 0; i < ultras.size(); i++) {
            if(i) cout << " ";
            cout << ultras[i]+1;
        }
        cout << "\n";

    }

}
