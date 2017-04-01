#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 400;

int n, m;
vector<vector<int>> board;

void swap_col(int i, int j) {
    for(int a = 0; a < n; a++) {
        swap(board[a][i], board[a][j]);
    }
}

void swap_row(int i, int j) {
    swap(board[i], board[j]);
}

int f[MAX], cnt[MAX];

int find(int x) {
    return f[x] = (x == f[x] ? x : find(f[x]));
}

void merge(int a, int b) {
    if(find(a) == find(b)) return;
    cnt[ find(b) ] += cnt[ find(a) ];
    f[find(a)] = find(b);
}

void init() {
    for(int i = 0; i < MAX; i++){
        f[i] = i;
        cnt[i] = 1;
    }
}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

    while(cin >> n >> m) {
        board = vector<vector<int>> (n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        init();

        int ans = 0;
        vector<int> tmp = board[0];
        sort(tmp.begin(), tmp.end());

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i == j) continue;
                if(tmp[i] == board[0][j])
                    merge(i, j);
            }
        }

        for(int i = 0; i < m; i++) {
            if(find(i) == i) {
                ans += cnt[i]-1;
            }
        }

        for(int i = 0; i < m; i++) {
            int mn = board[0][i], idx = -1;
            for(int j = i+1; j < m; j++) {
                if(board[0][j] < mn) {
                    mn = board[0][j];
                    idx = j;
                }
            }
            if(idx != -1) {
                swap_col(i, idx);
            }
        }

        init();

        int ans2 = 0;
        tmp.clear();
        for(int i = 0; i < n; i++)
            tmp.push_back(board[i][0]);

        sort(tmp.begin(), tmp.end());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(tmp[i] == board[j][0])
                    merge(i, j);
            }
        }

        for(int i = 0; i < n; i++) {
            if(find(i) == i) {
                ans += cnt[i]-1;
            }
        }

        for(int i = 0; i < n; i++) {
            int mn = board[i][0], idx = -1;
            for(int j = i+1; j < n; j++) {
                if(board[j][0] < mn) {
                    mn = board[j][0];
                    idx = j;
                }
            }
            if(idx != -1) {
                swap_row(i, idx);
            }
        }

        int id = 1;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
//                cout << board[i][j] << " ";
                ok &= board[i][j] == id;
                id++;
            }
//            cout << endl;
        }


        if(!ok) cout << "*\n";
        else cout << ans << "\n";
    }

}
