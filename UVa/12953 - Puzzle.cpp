#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 10000;
const int limit = 4e8;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m) {
        vector<vector<string>> board(n, vector<string>(m));
        vector<ll> row(n), col(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
            cin >> row[i];
        }
        for(int j = 0; j < m; j++) {
            cin >> col[j];
        }
        map<string, ll> known;
        bool change = true;
        while(change) {
            change = false;
            for(int i = 0; i < n; i++) {
                unordered_map<string, int> unknown;
                ll sum = row[i];
                for(int j = 0; j < m; j++) {
                    if(!known.count(board[i][j])) {
                        unknown[ board[i][j] ]++;
                    } else {
                        sum -= known[ board[i][j] ];
                    }
                }
                if(unknown.size() == 1) {
                    change = true;
                    auto it = unknown.begin();
                    known[it->first] = sum/it->second;
                }
            }

            for(int j = 0; j < m; j++) {
                unordered_map<string, int> unknown;
                ll sum = col[j];
                for(int i = 0; i < n; i++) {
                    if(!known.count(board[i][j])) {
                        unknown[ board[i][j] ]++;
                    } else {
                        sum -= known[ board[i][j] ];
                    }
                }
                if(unknown.size() == 1) {
                    change = true;
                    auto it = unknown.begin();
                    known[it->first] = sum/it->second;
                }
            }
        }

        for(auto &x: known) {
            cout << x.first << " " << x.second << "\n";
        }

    }

}
