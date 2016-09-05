#include <bits/stdc++.h>

#define PB push_back
#define ii pair< ll, ll >
#define state pair< int, ii >
#define MAX 100010
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

string rot = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n && n != 0) {
        string line; cin >> line;
        reverse(line.begin(), line.end());
        for(int i = 0; i < line.size(); i++) {
            int idx = rot.find(line[i]);
            idx = (idx + n) % int(rot.size());
            line[i] = rot[idx];
        }
        cout << line << "\n";
    }

}
