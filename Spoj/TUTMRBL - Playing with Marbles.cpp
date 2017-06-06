#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 3162280;
const double EPS = 1e-5;
const int INF = INT_MAX;

void factorize(int n, vector<int> &ans) {
    for(int p = 2; p*p <= n; p++) {
        while(n % p == 0) {
            n /= p;
            ans.push_back(p);
        }
    }
    if(n > 1) ans.push_back(n);
}

int get_squares(int n) {
    int ans = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n;
    while(cin >> n && n) {
        vector<int> ans;
        factorize(n, ans);
        cout << n << " = ";
        for(int i = 0; i < ans.size(); i++) {
            if(i) cout << " * ";
            cout << ans[i];
        }
        cout << "\nWith " << n << " marbles, " << get_squares(n) << " different rectangles can be constructed.\n";

    }
}
