#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ll long long
#define ii pair<int, int>
#define PB push_back
#define check x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_] && board[x_][y_] != '#'
#define MAX 100000 + 10
#define INF 1LL<<60
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

struct SegTree {
    int start, end;
    ll sum, cuad, equal, add;
    SegTree *left, *right;

    SegTree(int start, int end ) : start(start), end(end){
        sum = cuad = equal = add = 0;

        if(start == end) left = right = NULL;
        else {
            int mid = (start + end) / 2;
            left = new SegTree(start, mid);
            right = new SegTree(mid + 1, end);
        }
    }

    void update() {
        if(equal != 0) {
            if(left != NULL) {
                left -> equal = right -> equal = equal;
                left -> add = right -> add = 0;
            }
            cuad = (end - start + 1) * equal * equal;
            sum = (end - start + 1) * equal;
            equal = 0;
        }
        if(add != 0) {
            if(left != NULL) {
                left -> add += add;
                right -> add += add;
            }
            cuad = cuad + (end - start + 1) * add * add + 2 * add * sum;
            sum += (end - start + 1) * add;
            add = 0;
        }
    }

    void set(int from, int to, ll extra, bool all) {
        update();
        if(start == from && end == to) {
            if(all) { /// Todos iguales
                if(left != NULL) {
                    left -> equal = right -> equal = extra;
                    left -> add = right -> add = 0;
                }
                cuad = (end - start + 1) * extra * extra;
                sum = (end - start + 1) * extra;
            }
            else { /// Aumentar
                if(left != NULL) {
                    left -> add += extra;
                    right -> add += extra;
                }
                cuad = cuad + (end - start + 1) * extra * extra + 2 * extra * sum;
                sum += (end - start + 1) * extra;
            }
            return;
        }
        int mid = (start + end) / 2;
        if(to <= mid) left -> set(from, to, extra, all);
        else if(from > mid) right -> set(from, to, extra, all);
        else left -> set(from, mid, extra, all), right -> set(mid + 1, to, extra, all);

        left -> update();
        right -> update();

        sum = left -> sum + right -> sum;
        cuad = left -> cuad + right -> cuad;
    }

    ll get(int from, int to) {
        update();
        if(from == start && to == end) return cuad;
        int mid = (start + end) / 2;
        if(to <= mid) return left -> get(from, to);
        else if(from > mid) return right -> get(from, to);
        else return left -> get(from, mid) + right -> get(mid + 1, to);
    }
};

int nTest, cases, N, Q;

int main() {
    scanf("%d", &nTest);

    while(nTest--) {
        scanf("%d%d", &N, &Q);

        SegTree st = SegTree(1, N);

        ll aux;
        for(int i = 1; i <= N; i++) {
            scanf("%lld", &aux);
            st.set(i, i, aux, true);
        }

        printf("Case %d:\n", ++cases);
        while(Q--) {
            ll op, from, to, value;
            scanf("%lld", &op);

            if(op == 0) {
                scanf("%lld %lld %lld", &from, &to, &value);
                st.set(from, to, value, true);
            }
            if(op == 1) {
                scanf("%lld %lld %lld", &from, &to, &value);
                st.set(from, to, value, false);
            }
            if(op == 2) {
                scanf("%lld %lld", &from, &to);
                printf("%lld\n", st.get(from, to));
            }
        }
    }
}

