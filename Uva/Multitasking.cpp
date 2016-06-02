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

int n, m, f, t, d;
vector<ii> data;

int main() {
    //freopen("input.cpp", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d", &n, &m) > 0 && (n != 0 || m != 0)) {
        data.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &f, &t);
            data.PB(ii(f, 1));
            data.PB(ii(t, -1));
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &f, &t, &d);
            int cur = 0;
            while (f + cur <= 1000000) {
                data.PB(ii(f + cur, 1));
                data.PB(ii(min(t + cur, 1000000), -1));
                cur += d;
            }
        }
        sort(data.begin(), data.end());
        int cont = 0;
        bool ans = false;
        for(int i = 0; i < data.size(); i++) {
            if(cont >= 2) {
                ans = true;
                break;
            }
            cont += data[i].second;

        }
        if(!ans) printf("NO CONFLICT\n");
        else printf("CONFLICT\n");
    }
}

