#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 10000010;


int main() {
    freopen("win.in", "r", stdin);
    freopen("win.out", "w", stdout);


    int timelimit = 300*60;
    int n; cin >> n;
    vector<int> all(n);
    for(int i = 0; i < n; i++) {
        cin >> all[i];
    }

    sort(all.begin(), all.end());
    int i;
    for(i = 0; i < n && timelimit > 0; i++) {
        timelimit -= all[i];
    }
    if(timelimit < 0) i--;
    cout << i << "\n";



}
