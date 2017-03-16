#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX/2;
const int MAX = 1003;

int f[MAX], tam[MAX];

int find(int x) {
    return f[x] = (f[x] == x ? x : find(f[x]));
}

void merge(int a, int b) {
    if(find(a) == find(b)) return;
    tam[find(b)] += tam[find(a)];
    f[find(a)] = find(b);
}

void init() {
    for(int i = 0; i < MAX; i++) {
        f[i] = i;
        tam[i] = 1;
    }

}

string board[MAX];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    init();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'S') {
                merge(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'D') {
                if(find(i) == find(j)) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(find(i) == i)
            ans.push_back(tam[i]);
    }

    sort(ans.rbegin(), ans.rend());
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";


}
