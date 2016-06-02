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
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 1000000 * 2 + 10
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;

string toLowerCase(string s) {
    for(int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

map<string, vector<string> > m;
map<string, vector<string> >:: iterator it;
vector<string> ans;

string s;

int main() {
    while(cin >> s) {
        if(s == "#") break;
        string tmp = toLowerCase(s);
        sort(tmp.begin(), tmp.end());
        m[tmp].PB(s);
    }
    for(it = m.begin(); it != m.end(); it++)
        if((*it).second.size() == 1)
            ans.PB((*it).second[0]);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}
