#include <bits/stdc++.h>

#define PB push_back
#define iii pair<int, int>
#define MAX 100010
#define INF INT_MAX / 2
#define ll long long
#define MOD 1000000007L

using namespace std;


int minimumExpression(string &s) {
    s = s + s;
    int len = s.size(), i = 0, j = 1, k = 0;
    while(i + k < len && j + k < len) {
        if(s[i+k] == s[j+k]) k++;
        else if(s[i+k] > s[j+k]) { i = i+k+1; if(i <= j) i = j+1; k = 0; }
        else if(s[i+k] < s[j+k]) { j = j+k+1; if(j <= i) j = i+1; k = 0; }
   }
   return min(i, j);
}

int T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << minimumExpression(s) + 1 << "\n";
    }

}
