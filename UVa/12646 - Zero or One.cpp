#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 10005;
const double EPS = 1e-5;
const int INF = INT_MAX;

bool cnt[MAX][2];

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY
     int a, b, c;
     while(cin >> a >> b >> c) {
        if(a == b && b == c) cout << "*";
        else if(a != b && a != c) cout << "A";
        else if(b != a && b != c) cout << "B";
        else if(c != a && c != b) cout << "C";
        cout << "\n";
     }

}
