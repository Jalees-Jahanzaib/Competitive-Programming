#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;


int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    char line[10010];
    while(scanf("%s", line) > 0) {
        int n = strlen(line);
        stack<char> st;
        int i;
        for(i = 0; i < n; i++) {
            if(line[i] == '(' || line[i] == '[') {
                st.push(line[i]);
            }
            if(line[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else break;
            }
            if(line[i] == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else break;
            }
        }
        if(i == n && st.empty()) printf("YES\n");
        else printf("NO\n");
    }





}
