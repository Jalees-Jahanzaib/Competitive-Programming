#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 100005;
const double EPS = 1e-5;
const int INF = INT_MAX/2;

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, 1, -1};

struct point {
    ll x, y;
} points[MAX], S[MAX], pivot;

int n, sz;
int sqr ( ll x ) { return x * x; }
int dist ( const point &p, const point &q )
{ return sqr(p.x - q.x) + sqr(p.y - q.y); }

int orientation ( const point &p, const point &q, const point &r ) {
    return (q.x - p.x) * (r.y - q.y) -
           (q.y - p.y) * (r.x - q.x);
}
bool cmp ( const point &p, const point &q ) {
    ll o = orientation(pivot, p, q);
    if ( o != 0 ) return o > 0;
    return dist(pivot, p) < dist(pivot, q);
}

void convex_hull () {
    int best = 0;
    for ( int i = 1; i < n; ++i )
        if ( points[i].y < points[best].y ||
             (points[i].y == points[best].y &&
               points[i].x < points[best].x) )
             best = i;
    pivot = points[best];

    sort( points, points + n, cmp );

    int z = 1;
    for(int i = 1; i < n; i++) {
        while (i < n-1 && orientation(pivot, points[i], points[i+1]) == 0)
            i++;
        points[z] = points[i];
        z++;
    }
    n = z;
    assert(n >= 3);

    S[0] = points[0]; S[1] = points[1]; S[2] = points[2];
    sz = 3;
    for ( int i = 3; i < n; ++i ) {
        /// add && sz >= 3 in case of 4 collinear points only are given.
        /// tle with < 0
        while ( orientation(S[sz - 2], S[sz - 1], points[i]) <= 0 )
            --sz;
        S[sz++] = points[i];
    }
}

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // LOCAL

    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        convex_hull();

//        cout << "sz = " << sz << endl;
//
//        for(int i = 0; i < sz; i++) {
//            cout << S[i].x << " " << S[i].y << endl;
//        }

        int m; cin >> m;
        while(m--) {
            bool inside = true;
            point pt;
            cin >> pt.x >> pt.y;
            for(int i = 0; i < sz; i++) {
//                cout << orientation(points[i], points[(i+1)%n], pt) << endl;
                if(orientation(S[i], S[(i+1)%sz], pt) < 0) {
                    inside = false;
                }
            }
            cout << (inside ? "inside" : "outside") << "\n";
        }
    }
}
