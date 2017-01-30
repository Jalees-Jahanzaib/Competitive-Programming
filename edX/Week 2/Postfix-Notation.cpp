#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;


int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    char line;
    stack<int> st;
    while(scanf(" %c", &line) > 0) {
        if(line == '+') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(a+b);
        }
        else if(line == '-') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(a-b);
        }
        else if(line == '*') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(a*b);
        }
        else {
            st.push(line - '0');
        }
    }
    printf("%d\n", st.top());







}
