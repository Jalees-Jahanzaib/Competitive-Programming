#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#include<math.h>
#include<cstring>
#define PB push_back
using namespace std;
typedef pair<int, int> ii;

struct SegTree{
    int start, end, minValue;
    SegTree *left, *right;
    SegTree(int start, int end) : start(start), end(end) {
        minValue = 0;
        if(start == end) left = right = NULL;
        else {
            int mid = (start + end) / 2;
            left = new SegTree(start, mid);
            right = new SegTree(mid + 1, end);
        }
    }

    void set(int from, int newValue) {
        if(start == end) {
            minValue = newValue;
            return;
        }
        int mid = (start + end) / 2;
        if(from <= mid) left -> set(from, newValue);
        else right -> set(from, newValue);
        minValue = min(left -> minValue, right -> minValue);
    }

    int get(int from, int to) {
        if(from == start && to == end) return minValue;
        int mid = (start + end) / 2;
        if(to <= mid) return left -> get(from, to);
        else if(from > mid) return right -> get(from, to);
        else return min(left -> get(from, mid), right -> get(mid + 1, to));
    }
};

int nTest, N, a, b, cases, M;

int main() {
    scanf("%d", &nTest);
    while(nTest--) {
        scanf("%d%d", &N, &M);
        SegTree st = SegTree(1, N);
        for(int i = 1; i <= N; i++) scanf("%d", &a), st.set(i, a);
        printf("Scenario #%d:\n", ++cases);
        while(M--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", st.get(a, b));

        }
    }
}
