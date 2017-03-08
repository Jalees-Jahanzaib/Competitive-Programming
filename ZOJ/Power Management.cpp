#include<bits/stdc++.h>

#define t first.first
#define type first.second
#define name second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, string> iis;

const int INF = INT_MAX;
const ll MAX = LLONG_MAX/3LL;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

map<string, int> power;

string getname(){
    string name = "";
    char ch;
    while((ch = getchar()) != '[');
    while((ch = getchar()) != ']'){
        name += ch;
    }
    return name;
}

void solve(int n, int p) {
    vector<int> cnt(32778);
    for(int i = 0; i < n; i++) {
        string s; int a, b;
        s = getname();
        scanf("%d%d", &a, &b);
        cnt[a] += power[s];
        cnt[b] -= power[s];
    }
    int mx = -1, curp = 0;
    for(int i = 0; i < cnt.size(); i++) {
        if(cnt[i] != 0) {
            curp += cnt[i];
            mx = max(mx, curp);
            if(curp > p) {
                printf("The power will be out at time %d because the power is %d Watts and overloaded.\n" , i, curp);
                return;
            }
        }
    }

    printf("The maximum power needed is %d Watts.\n" , mx);
}

int main( ) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string s; int d;
        s = getname();
        scanf("%d", &d);
        power[s] = d;
    }
    int p;
    while(scanf("%d%d", &n, &p) == 2) {
        solve(n, p);
    }

}

