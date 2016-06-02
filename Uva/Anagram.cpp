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
#include<utility>
#include<sstream>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 1000 + 10
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
int nTest;
string a;
bool visited[MAX];
map<string, bool> dp;

bool cmp (char a, char b) {
    if(tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

void printNext(string cur) {
    if(dp[cur]) return;
    dp[cur] = true;
    if(cur.size() == a.size()) {
        printf("%s\n", cur.c_str());
        return;
    }
    for(int i = 0; i < a.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            printNext(cur + a[i]);
            visited[i] = false;
        }
    }
}


int main() {
    scanf("%d", &nTest);
    while(nTest--) {
        cin >> a;
        memset(visited, false, sizeof(a.size() + 1));
        sort(a.begin(), a.end(), cmp);
        dp.clear();
        printNext("");
    }
}//NEXT PERMUTATION
