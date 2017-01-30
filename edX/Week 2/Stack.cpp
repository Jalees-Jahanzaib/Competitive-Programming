#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;


int main() {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);

    int n; scanf("%d", &n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        char c; int x; scanf(" %c", &c);
        if(c == '+') {
            scanf("%d", &x);
            st.push(x);
        }
        else {
            printf("%d\n", st.top());
            st.pop();
        }
    }

}
