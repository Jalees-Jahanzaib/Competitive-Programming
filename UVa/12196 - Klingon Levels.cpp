#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 1010
#define MAXN 10010
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int tree[MAX][MAXN], cnt[MAXN], MAXV;

void update(int pos, int value, int id) {
    for(; pos <= MAXV; pos += pos&-pos)
        tree[pos][id] += value;
}

int get(int pos, int id) {
    int sum = 0;
    for(; pos > 0; pos -= pos&-pos)
        sum += tree[pos][id];
    return sum;
}

int n;

int f(int pos) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = get(MAXV - pos + 1, i);
        ans += abs( x - (cnt[i] - x) );
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n && n != 0) {
        memset(tree, 0, sizeof tree);
        int k, x, best = INF;
        MAXV = 0;
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            cin >> cnt[i];
            v[i] = vector<int>(cnt[i]);
            for(int j = 0; j < cnt[i]; j++) {
                cin >> v[i][j];
                v[i][j]++;
                MAXV = max(MAXV, v[i][j]);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < cnt[i]; j++) {
                update(MAXV - v[i][j] + 1, 1, i);
            }
        }

        for(int i = 1; i <= MAXV; i++) best = min(best, f(i));

        cout << best << "\n";
    }
}
