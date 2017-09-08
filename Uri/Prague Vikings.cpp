#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e4 + 10;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n;
    while(cin >> n && n) {
        deque<char> all;
        for(char i = 'A'; i <= 'Z'; i++) {
            all.push_back(i);
        }
        cout << "Instancia " << ++cases << "\n";
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            char c = all[x-1];
            cout << c;
            all.erase(all.begin() + x - 1);
            all.push_front(c);
        }
        cout << "\n\n";
    }

}
