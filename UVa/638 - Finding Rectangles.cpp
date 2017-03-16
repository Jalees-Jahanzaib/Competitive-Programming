#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX/2;
const int MAX = 55;

char label[MAX][MAX];
bool exist[MAX][MAX];
int cases;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int n;
    while(cin >> n && n) {
        vector<ii> p(n);
        memset(exist, false, sizeof exist);
        for(int i = 0; i < n; i++) {
            char c; cin >> c >> p[i].x >> p[i].y;
            label[ p[i].x ][ p[i].y ] = c;
            exist[ p[i].x ][ p[i].y ] = true;
        }

        set<string> ans;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int mnx = min(p[i].x, p[j].x), mxx = max(p[i].x, p[j].x);
                int mny = min(p[i].y, p[j].y), mxy = max(p[i].y, p[j].y);
                if(mnx != mxx && mny != mxy) {
                    string cur = "";
                    if(exist[mnx][mxy]) cur.push_back( label[mnx][mxy] );
                    if(exist[mxx][mxy]) cur.push_back( label[mxx][mxy] );
                    if(exist[mxx][mny]) cur.push_back( label[mxx][mny] );
                    if(exist[mnx][mny]) cur.push_back( label[mnx][mny] );
                    if(cur.size() == 4)
                        ans.insert(cur);
                }
            }
        }

        cout << "Point set " << ++cases << ":";
        if(ans.size() == 0) {
            cout << " No rectangles\n";
            continue;
        }
        cout << "\n";
        int i = 0;
        for(auto &x : ans) {
            cout << " " << x;
            i++;
            if(i == 10) {
                cout << "\n";
                i = 0;
            }
        }
        if(i != 0) cout << "\n";
    }

}
