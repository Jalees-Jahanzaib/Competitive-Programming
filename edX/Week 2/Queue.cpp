#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;


int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    int n; scanf("%d", &n);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        char c; int x; scanf(" %c", &c);
        if(c == '+') {
            scanf("%d", &x);
            q.push(x);
        }
        else {
            printf("%d\n", q.front());
            q.pop();
        }
    }

}
