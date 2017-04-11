#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 40000;
const double EPS = 1e-5;
const int INF = INT_MAX;

int phi[MAX];

void KMP (string &p, string &t) {
    phi[0] = -1;
    for (int i = 0, j = -1; i < p.size();) {
        while( j > -1 && p[j] != p[i]) j = phi[j];
        i++; j++;
        phi[i] = j;
    }
    for(int i = 0, j = 0; i < t.size();) {
        while(j > -1 && p[j] != t[i]) j = phi[j];
        i++; j++;
        if(j == p.size()) {
            j = phi[j];
            cout << i - int(p.size()) << "\n";
        }
    }
}


int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n, first = 0;
    while(cin >> n) {
        if(first) cout << "\n";
        first = 1;
        string p, t; cin >> p >> t;
        KMP(p, t);
    }


}
