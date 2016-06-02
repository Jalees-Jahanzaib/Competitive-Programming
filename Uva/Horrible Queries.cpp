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

using namespace std;

int nTest, N, C;

struct SegTree {
    int start, end;
    ll value, toUpdate;
    SegTree *left, *right;
    SegTree(int start, int end) : start(start), end(end) {
        value = 0;
        toUpdate = 0;
        int mid = (start + end) / 2;
        if(start == end) left = right = NULL;
        else {
            left = new SegTree(start, mid);
            right = new SegTree(mid + 1, end);
        }
    }

    void update() {
        if(toUpdate > 0) {
            value += toUpdate * (ll)(end - start + 1L);
            if(left != NULL) left -> toUpdate += toUpdate, right -> toUpdate += toUpdate;
            toUpdate = 0;
        }
    }

    void set(int from, int to, ll add) {
        update();
        if(from == start && to == end) {
            value += add * (ll)(end - start + 1L);
            if(left != NULL) left -> toUpdate += add, right -> toUpdate += add;
            //cout << "->->->->-> " <<toUpdate << endl;
            return;
        }
        int mid = (start + end) / 2;
        if(to <= mid) left -> set(from, to, add);
        else if(from > mid) right -> set(from, to, add);
        else left -> set(from, mid, add), right -> set(mid + 1, to, add);
        left -> update(), right -> update();
        value = left -> value + right -> value;
    }

    ll get(int from, int to) {
        update();
        if(from == start && end == to) return value;
        int mid = (start + end) / 2;
        if(to <= mid) return left -> get(from, to);
        else if(from > mid) return right -> get(from, to);
        else return left -> get(from, mid) + right -> get(mid + 1, to);
    }
};

int a, b, op;
ll c;

int main() {
    //freopen("input.cpp", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &nTest);
    while(nTest--) {
        scanf("%d%d", &N, &C);
        SegTree st(1, N);
        for(int i = 0; i < C; i++) {
            scanf("%d", &op);
            if(op == 0) {
                scanf("%d%d%lld", &a, &b, &c);
                st.set(a, b, c);
            }
            else {
                scanf("%d%d", &a, &b);
                printf("%lld\n", st.get(a, b));
            }
        }
    }
}
