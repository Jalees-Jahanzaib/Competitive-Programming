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
#define MAX 1000000 + 100

using namespace std;

int nTest, N, C, arr[MAX];

struct SegTree {
    int start, end;
    set<int> s;
    SegTree *left, *right;
    SegTree(int start, int end) : start(start), end(end) {
        int mid = (start + end) / 2;
        if(start == end) {
            left = right = NULL;
            s.insert(arr[start]);
        }
        else {
            left = new SegTree(start, mid);
            right = new SegTree(mid + 1, end);
            s = left -> s;
            for(set<int>::iterator it = (right -> s).begin(); it != (right -> s).end(); it++) s.insert(*it);
        }
    }

    int get(int from, int to) {
        cout << start <<" "<< end << endl;
        if(from == start && end == to) return s.size();
        int mid = (start + end) / 2;
        if(to <= mid) return left -> get(from, to);
        else if(from > mid) return right -> get(from, to);
        else return left -> get(from, mid) + right -> get(mid + 1, to);
    }
};

int a, b, op;
ll c;

int main() {
    freopen("input.cpp", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    SegTree st(1, N);
    scanf("%d", &C);
    for(int i = 0; i < C; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", st.get(a, b));
    }
}
