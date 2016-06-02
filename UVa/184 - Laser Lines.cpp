#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ll long long
#define dd pair<double, double>
#define ii pair<int, int>
#define PB push_back
#define checkk x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 3 * (int(1e5) + 10)
#define INF LONG_LONG_MAX / 6;
#define INF2 LONG_LONG_MAX / 6
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2
#define PI acos(-1)

using namespace std;

struct Line {
    int A, B, C;

    Line(int x1, int y1, int x2, int y2) {
        A = y2 - y1;
        B = x1 - x2;
        C = A*x1 + B*y1;
    }
};

bool online(Line l, ii p) {
    return l.A*p.first + l.B*p.second == l.C;
}

int main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    //freopen("input.txt", "r", stdin)
    int x1, y1;
    while(cin >> x1 >> y1 && (x1 != 0 || y1 != 0)) {
        vector<ii> p;
        p.PB(ii(x1, y1));
        while(cin >> x1 >> y1 && (x1 != 0 || y1 != 0)) p.PB(ii(x1, y1));

        vector<vector<ii> > ans;
        bool seen[310][310];
        memset(seen, false, sizeof(seen));
        for(int i = 0; i < p.size(); i++) {
            for(int j = i + 1; j < p.size(); j++) {
                if(seen[i][j] || seen[j][i]) continue;

                Line l = Line(p[i].first, p[i].second, p[j].first, p[j].second);
                vector<ii> cur;
                vector<int> pos;
                for(int k = 0; k < p.size(); k++) {
                    if(online(l, p[k])) {
                        cur.PB(p[k]);
                        pos.PB(k);
                    }
                }
                if(cur.size() >= 3) {
                    for(int i = 0; i < pos.size(); i++)
                        for(int j = 0; j < pos.size(); j++)
                            seen[pos[i]][pos[j]] = seen[pos[j]][pos[i]] = true;
                    sort(cur.begin(), cur.end());
                    ans.PB(cur);
                }
            }
        }

        sort(ans.begin(), ans.end());

        if(ans.size() != 0) {
            printf("The following lines were found:\n");
            for(int i = 0; i < ans.size(); i++) {
                for(int j = 0; j < ans[i].size(); j++)
                    printf("(%4d,%4d)", ans[i][j].first, ans[i][j].second);
                printf("\n");
            }
        }
        else printf("No lines were found\n");
    }

}
