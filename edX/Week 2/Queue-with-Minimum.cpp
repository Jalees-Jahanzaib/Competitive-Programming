#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;


int main() {
    freopen("queuemin.in", "r", stdin);
    freopen("queuemin.out", "w", stdout);

    int n; scanf("%d", &n);
    queue<int> q;
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        char c; int x; scanf(" %c", &c);
        if(c == '+') {
            scanf("%d", &x);
            q.push(x);
            while(!dq.empty() && dq.back() > x ) dq.pop_back();
            dq.push_back(x);
        }
        else if(c == '-'){
            if(q.front() == dq.front()) dq.pop_front();
            q.pop();
        }
        else {
            printf("%d\n", dq.front());
        }
    }

}
