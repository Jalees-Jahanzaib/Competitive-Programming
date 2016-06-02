#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 2000
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int N, dpyes[MAX], dpno[MAX];
vector< vector<int> > G;

void go(int u, int p) {
    int yes = 1, no = 0;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == p) continue;
        go(v, u);
        yes += min(dpyes[v], dpno[v]);
        no += dpyes[v];
    }
    dpyes[u] = yes;
    dpno[u] = no;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    while(cin >> N && N != 0) {
        G = vector< vector<int> >(N + 3);

        int c, a;
        for(int i = 1; i <= N; i++) {
            cin >> c;
            for(int j = 0; j < c; j++) {
                cin >> a;
                G[i].PB(a);
            }
        }

        if(N == 1) cout << "1\n";

        go(1, 0);

//        for(int i = 1; i <= N; i++) cout << dpyes[i] << " - " << dpno[i] << endl;

        cout << min(dpyes[1], dpno[1]) << "\n";

    }


}
