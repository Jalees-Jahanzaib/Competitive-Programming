/*
ID: odjimen1
LANG: C++
TASK: beads
*/

#include<iostream>
#include<fstream>
#include<math.h>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>

#define ii pair<int, char>
#define PB push_back
#define check x >= 0 && y >= 0 && x < R && y < C && !board[x][y]

using namespace std;

int a, n, best;
string s;
vector<int> track, cur, ans;

bool seen[5000][5000];

void print() {
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "sum:" << best;
    cout << "\n";
}

void solve(int index, int sum) { ///Mejor si miro, de los que falta me srve alguno
    seen[index][sum] = true;
    if(sum > best) {
        best = sum;
        ans = cur;
    }

    if(index == track.size()) return;

    for(int i = index; i < track.size(); i++) {
        if(sum + track[i] > n) continue;
        if(seen[i + 1][sum + track[i]]) return;
        cur.PB(track[i]);
        solve(i + 1, sum + track[i]);
        cur.pop_back();
    }
}

int main() {
    //freopen("beads.in", "r", stdin);
    //freopen("beads.out", "w", stdout);
    while(getline(cin, s)) {
        track.clear();
        ans.clear();
        best = -1;
        memset(seen, false, sizeof seen);

        istringstream ss(s);
        ss >> n >> a;
        while(ss >> a) track.PB(a);

        solve(0, 0);

        print();

    }




}
