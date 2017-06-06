#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 1005;
const int INF = INT_MAX/3;
const int MAXLOG = 20;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n;
    while(cin >> n && n) {
        deque<int> all(n);
        for(int i = 0; i < n; i++) {
            all[i] = i+1;
        }
        vector<int> ans;
        while(all.size() > 1) {
            ans.push_back(all.front());
            all.pop_front();
            all.push_back(all.front());
            all.pop_front();
        }

        cout << "Discarded cards: ";
        for(int i = 0; i < ans.size(); i++) {
            if(i) cout << ", ";
            cout << ans[i];
        }
        cout << "\nRemaining card: " << all[0]<< "\n";
    }
}
