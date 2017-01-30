#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef double ll;
typedef pair<ll, ll> ii;

const int INF = INT_MAX;
const int MAX = 100000;

ll sqr(ll a) {
    return a*a;
}

ll dist(ii a, ii b) {
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

struct cmp {
    bool operator()(ii a, ii b) {
        return a.y < b.y;
    }
};

int main( ) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    while(scanf("%d", &n) > 0 && n != 0) {
        vector<ii> p(n);
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }

        sort(p.begin(), p.end());

        set<ii, cmp> near_points;
        ll best_dist = LLONG_MAX/10;
        for(int i = 0; i < n; i++) {
            ii cur = p[i];
            vector<ii> to_erase;
            for(auto &o : near_points) {
                if(sqr(cur.x - o.x) > best_dist)
                    to_erase.push_back(o);
            }
            for(auto &o : to_erase) {
                near_points.erase(o);
            }

            if(near_points.size()) {
                auto it = near_points.lower_bound(cur);
                for(auto j = it; j != near_points.end() && sqr((*j).y - cur.y) <= best_dist; j++) {
                    best_dist = min(best_dist, dist(cur, *j));
                }
                if(it != near_points.begin()) {
                    for(auto j = --it; j != near_points.begin() && sqr((*j).y - cur.y) <= best_dist; j--) {
                        best_dist = min(best_dist, dist(cur, *j));
                    }
                }
                best_dist = min(best_dist, dist(cur, *near_points.begin()));
            }
            near_points.insert(cur);
        }

        if(best_dist >= 100000000.0) printf("INFINITY\n");
        else {
            printf("%.4f\n", sqrt(best_dist));
        }
    }
}
