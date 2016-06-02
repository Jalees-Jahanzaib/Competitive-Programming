#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>

#define MP make_pair
#define MT make_tuple
#define PB push_back
#define MAX 501000
#define MOD 101
#define ll long long
using namespace std;

string from, to;
bool a, b;
ll c, A[] = {6760000, 10000, 1000, 100, 10, 1}, B[] = {19448100, 926100, 44100, 2100, 100, 10, 1};
int alph[] = {0, 1, 0, 2, 2, 2, 2, 2, 0, 3, 3, 3, 0, 4, 4, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

ll transformA(string s) {
    ll ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') ans += (ll)(s[i] - 'A') * A[i];
        else ans += (ll)(s[i] - '0') * A[i];
    }
    return ans;
}

ll transformB(string s) {
    ll ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') ans += (ll)(s[i] - 'A') * B[i];
        else ans += (ll)(s[i] - '0') * B[i];
    }
    return ans;
}

ll solve() {
    if(a && b) return transformA(to) - transformA(from);
    if(!a && !b) return transformB(to) - transformB(from);
    if(a && !b) return (ll)(transformB(to)) - (ll)(transformA("ZZZ9999") - transformA(from)) + 1LL;
    return -1;
}

bool validate() {
    bool ans = true;
    if(b) {
        for(int i = 0; i < 3; i++) ans &= to[i] >= 'A' && to[i] <= 'Z';
        for(int i = 3; i < to.size(); i++) ans &= to[i] >= '0' && to[i] <= '9';
    }
    else {
        for(int i = 0; i < 5; i++) ans &= to[i] >= 'A' && to[i] <= 'Z';
        for(int i = 5; i < to.size(); i++) ans &= to[i] >= '0' && to[i] <= '9';
        for(int i = 0; i < to.size(); i++) {
                ans &= to[i] != 'A' && to[i] != 'C' && to[i] != 'M' && to[i] != 'I' && to[i] != 'P';
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    while(cin >> from >> to >> c && from != "*") {
        a = from[3] >= '0' && from[3] <= '9';
        b = to[3] >= '0' && to[3] <= '9';
        if(!validate()) {
            cout << "N\n";
            continue;
        }
        if((!a && b )) {
            cout << "N\n";
            continue;
        }
        if(!a) for(int i = 0; i < 5; i++) from[i] = (from[i] - alph[from[i] - 'A']);
        if(!b) for(int i = 0; i < 5; i++) to[i] = (to[i] - alph[to[i] - 'A']);
        ll ans = solve();
        if(ans <= c && ans > 0) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
