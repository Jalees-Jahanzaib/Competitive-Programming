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
using namespace std;
#define ii pair<int, int>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 100000 + 100
#define LIMIT 1000000
#define MOD 1000000000

struct SegTree {
    int start, end, value;
    SegTree *left, *right;

    SegTree(int start, int end) : start(start), end(end) {
        value = 0;
        if(start == end) {
            left = right = NULL;
        }
        else {
            int mid = (start + end) / 2;
            left = new SegTree(start, mid);
            right = new SegTree(mid + 1, end);
        }
    }

    void set(int x, int newValue) {
        if(start == end) {
            value = (newValue >= 0 ? (newValue == 0 ? 0 : 1) : -1);
            return;
        }
        int mid = (start + end) / 2;
        if(x <= mid) left -> set(x, newValue);
        else right -> set(x, newValue);
        value = left -> value * right -> value;
    }

    int get(int from, int to) {
        if(start == from && to == end) return value;
        int mid = (start + end) / 2;
        if(to <= mid) return left -> get(from, to);
        else if(from > mid) return right -> get(from, to);
        else return left -> get(from, mid) * right -> get(mid + 1, to);
    }

};

int n, k, f, t;
char op;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d", &n, &k) > 0) {
        SegTree st(1, n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &f);
            st.set(i, f);
        }
        for(int i = 1; i <= k; i++) {
            scanf(" %c %d %d", &op, &f, &t);
            if(op == 'C') st.set(f, t);
            else {
                f = st.get(f, t);
                if(f == 0) printf("0");
                else if(f < 0) printf("-");
                else if(f > 0) printf("+");
            }
        }
        printf("\n");
    }

}

