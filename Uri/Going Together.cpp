#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 1e1 + 10;
const int INF = INT_MAX;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

const int DX[] = {0, 0, -1, 1};
const int DY[] = {1, -1, 0, 0};

string board[MAX];
int seen[MAX][MAX][MAX][MAX][MAX][MAX];
int cases, n, tag = 1;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool can(int idx, int x, int y, vector<int> &c) {
    for(int i = 0; i < 6; i += 2) {
        if(idx == i) continue;
        if(c[i] == x && c[i+1] == y) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        cin >> n;

        queue<int> q;
        vector<int> p;

        for(int i = 0; i < n; i++) {
            cin >> board[i];
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'A' || board[i][j] == 'B' || board[i][j] == 'C') {
                    q.push(i);
                    q.push(j);
                    p.push_back(i);
                    p.push_back(j);
                }
            }
        }

        int ans = -1;
        seen[ p[0] ][ p[1] ][ p[2] ][ p[3] ][ p[4] ][ p[5] ] = tag;
        vector<int> c(6), o(6);
        q.push(0);

        while(q.size()) {
            for(int i = 0; i < 6; i++) {
                c[i] = q.front(); q.pop();
            }

            int d = q.front(); q.pop();

            bool ok = true;
            for(int i = 0; i < 6; i += 2) {
                ok &= board[ c[i] ][ c[i+1] ] == 'X';
            }
            if(ok) {
                ans = d;
                break;
            }
            for(int i = 0; i < 4; i++ ){
                for(int k = 0; k < 6; k += 2) {
                    o[k] = c[k] + DX[i];
                    o[k+1]= c[k+1] + DY[i];
                }
                for(int times = 0; times < 5; times++)
                    for(int k = 0; k < 6; k += 2) {
                        if(!check(o[k], o[k+1]) || !can(k, o[k], o[k+1], o) || board[ o[k] ][ o[k+1] ] == '#')
                            o[k]= c[k], o[k+1] = c[k+1];
                    }

                if( seen[ o[0] ][ o[1] ][ o[2] ][ o[3] ][ o[4] ][ o[5] ] != tag ) {
                    seen[ o[0] ][ o[1] ][ o[2] ][ o[3] ][ o[4] ][ o[5] ] = tag;
                    for(int l = 0; l < 6; l++) {
                        q.push(o[l]);
                    }
                    q.push(d+1);
                }
            }
        }

        cout << "Case " << ++cases << ": ";
        if(ans == -1)cout << "trapped\n";
        else cout << ans << "\n";

        tag++;
    }
}
