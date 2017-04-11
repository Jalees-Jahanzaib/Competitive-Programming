#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 300015;
const double EPS = 1e-5;
const int INF = INT_MAX;
const ll MOD = int(1e9) + 7;

int phi[MAX];

int preprocessing (string &p) {
    phi[0] = -1;
    for (int i = 0, j = -1; i < p.size();) {
        while( j > -1 && p[j] != p[i]) j = phi[j];
        i++; j++;
        phi[i] = j;
    }
}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

    string s;
    while(cin >> s) {
        string c = s;
        reverse(c.begin(), c.end());
        c = c+s;
        preprocessing(c);
        int k = min(int(s.size()), phi[int(c.size())]);
        int n = s.size();
        for(int i = (n-k-1); i >= 0; i--) {
            s.push_back(s[i]);
        }

        cout << s << "\n";

    }

}
