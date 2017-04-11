#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 201;
const double EPS = 1e-5;
const int INF = INT_MAX;

bool can[MAX][MAX][27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n;
    while(cin >> n && n) {

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < 26; k++) {
                    if(i == j) can[i][j][k] = true;
                    else can[i][j][k] = false;
                }

        int a, b;
        while(cin >> a >> b && (a+b)) {
            a--; b--;
            string s; cin >> s;
            for(int i = 0; i < s.size(); i++) {
                can[a][b][ s[i]-'a' ] = true;
            }
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int l = 0; l < 26; l++) {
                        can[i][j][l] |= can[i][k][l]&can[k][j][l];
                    }
                }
            }
        }

        while(cin >> a >> b && (a+b)) {
            a--; b--;
            string s;
            for(int i = 0; i < 26; i++) {
                if(can[a][b][i])
                    s.push_back(i+'a');
            }
            if(s == "") s = "-";
            cout << s << "\n";
        }

        cout << "\n";

    }

}
