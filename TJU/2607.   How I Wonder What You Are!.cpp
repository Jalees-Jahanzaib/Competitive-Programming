#include<bits/stdc++.h>

#define x first
#define y second.first
#define z second.second

using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<lf, lf> ii;
typedef pair<lf, ii> iii;

const int INF = INT_MAX;
const ll MAX = 100000;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

lf len(iii a) {
    return sqrt((a.x)*(a.x) + (a.y)*(a.y) + (a.z)*(a.z));
}
lf dot(iii a, iii b) {
    return a.x*b.x + a.y*b.y +a.z*b.z;
}
lf angle ( iii A, iii B) { return acos( dot(A, B)/(len(A)*len(B)) ); }

const lf PI = acos(-1);
const lf EPS = 1e-10;

int cmp ( lf A, lf B ) { return ( A+EPS < B ? -1 : ( B+EPS < A ? 1 : 0 ) ); }

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    while(cin >> n && n != 0) {
        vector<iii> star(n);
        for(int i = 0; i < n; i++) {
            cin >> star[i].x >> star[i].y >> star[i].z;
        }
        int m; cin >> m;
        vector<iii> tele(m);
        vector<lf> ang(m);
        vector<bool> ans(n);
        for(int i = 0; i < m; i++) {
            cin >> tele[i].x >> tele[i].y >> tele[i].z >> ang[i];
            for(int j = 0; j < n; j++) {
                lf angl = angle(star[j], tele[i]);
                if(cmp(angl, ang[i]) < 0)
                    ans[j] = true;

            }
        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            total += ans[i];
        }
        cout << total << "\n";
    }

}


