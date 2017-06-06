#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e3 + 10;
const int INF = INT_MAX/3;
const int MAXLOG = 20;
const ll MOD = 1e9+7;

typedef double lf;
typedef complex<lf> pt;
const lf PI = acos(-1);
const lf EPS = 1e-10;
#define x(P)		real(P)
#define y(P)		imag(P)
#define cross(A,B)		imag(conj((A))*(B))
#define dot(A,B)		real(conj((A))*(B))
int cmpP ( lf A, lf B ) { return ( A+EPS < B ? -1 : ( B+EPS < A ? 1 : 0 ) ); }

typedef pair<pt, int> pti;

pt pivot = pt(0, 0);

int orientation(pt p, pt q, pt r) {
    return cmpP(cross(q-p, r-p), 0); /// 0->colineal, 1->left, -1->right
}

struct Event {
    pt point;
    int idx, open;

    Event(pt point, int idx, int open) : point(point), idx(idx), open(open) {}

    bool operator < (const Event &o) {
        int xd = orientation(pivot, point, o.point);
        if(xd != 0) return xd == -1;
        return open < o.open;
    }
};

istream& operator >> ( istream& in, pt& p ) {
    lf x,y; in >> x >> y;
    p = pt(x,y); return in;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // FSOCIETY

    int n;
    while(cin >> n && n) {
        vector<Event> events;
        for(int i = 0; i < n; i++) {
            pt xx, yy; cin >> xx >> yy;
            if(orientation(pivot, xx, yy) > 0)
                swap(xx, yy);
            events.push_back( Event( xx, i, -1) );
            events.push_back( Event( yy, i, 1) );
        }

        sort(events.begin(), events.end());
        set<int> done;
        stack<int> opened;
        int ans = 0;

        for(int i = 0; i < events.size(); i++) {
            if(events[i].open == -1) {
                opened.push(events[i].idx);
            } else {
                if(!done.count(events[i].idx)) {
                    ans++;
                    while(opened.size()) {
                        done.insert(opened.top());
                        opened.pop();
                    }
                }
            }
        }

        cout << ans << "\n";

    }
}
