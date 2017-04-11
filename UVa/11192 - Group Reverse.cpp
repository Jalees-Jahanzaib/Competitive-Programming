#include<bits/stdc++.h>
#include<time.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<double, ii> iii;

const int MAX = 200005;
const double EPS = 1e-5;
const int INF = INT_MAX;

void doit(int i, int j, string &s) {
    while(i < j) {
        swap(s[i], s[j]);
        i++; j--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

//    srand(time(0));

    int g;
    while(cin >> g && g != 0) {
        string s; cin >> s;
        int k = int(s.size())/ g;
        for(int i = 0; i < s.size(); i += k) {
            doit(i, i+k-1, s);
        }
        cout << s << "\n";
    }
}
