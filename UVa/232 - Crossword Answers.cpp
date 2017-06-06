#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;

const int MAX = 20;
const int INF = INT_MAX/3;
const int MAXLOG = 20;

string board[MAX];
int n, m;

bool elegible(int x, int y) {
    if(x < 0 || y < 0) return true;
    return board[x][y] == '*';
}

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && board[x][y] != '*';
}

int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    while(cin >> n && n) {
        cin >> m;
        for(int i = 0; i < n; i++) {
            cin >> board[i];
        }
        vector<string> cross, down;
        vector<int> numberc, numberd;
        int q = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool in = false;
                if(elegible(i, j-1) && board[i][j] != '*') {
                    q++;
                    in = true;
                    string tmp;
                    for(int x = i, y = j; check(x, y); y++) {
                        tmp.push_back(board[x][y]);
                    }
                    cross.push_back(tmp);
                    numberc.push_back(q);
                }
                if(elegible(i-1, j) && board[i][j] != '*') {
                    if(!in) q++;
                    string tmp;
                    for(int x = i, y = j; check(x, y); x++) {
                        tmp.push_back(board[x][y]);
                    }
                    down.push_back(tmp);
                    numberd.push_back(q);
                }
            }
        }

        if(cases) cout << "\n";
        cout << "puzzle #" << ++cases << ":\n";
        cout << "Across\n";
        for(int i = 0; i < cross.size(); i++) {
            cout << setw(3) << numberc[i] << "." << cross[i] << "\n";
        }
        cout << "Down\n";
        for(int i = 0; i < down.size(); i++) {
            cout << setw(3) << numberd[i] << "." << down[i] << "\n";
        }

    }

}
