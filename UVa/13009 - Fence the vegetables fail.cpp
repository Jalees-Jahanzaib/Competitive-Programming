#include<bits/stdc++.h>

using namespace std;

#define idx first.second
#define y1 second.first
#define y2 second.second

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

const int INF = INT_MAX;
const int MAX = 500010;

int bit[MAX];

void update(int x, int val) {
    for(; x < MAX; x += -x&x) {
        bit[x] += val;
    }
}

void update_range(int a, int b) {
    if(a > b) swap(a, b);
    update(a, 1); update(b+1, -1);
}

int get(int x) {
    int ans = 0;
    for(; x > 0; x -= -x&x) {
        ans += bit[x];
    }
    return ans&1;
}

void compress(vector<ii> &x, vector<int> &p, bool ok = false) {
    for(int i = 0; i < x.size(); i++) {
        x[i].second = lower_bound(p.begin(), p.end(), x[i].second) - p.begin() + 1;
        x[i].second *= 2;
        if(ok) x[i].second++;
    }
}

int main( ) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    while(scanf("%d%d", &n, &m) > 0) {
        vector<int> ys;
        vector<ii> plant(n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &plant[i].first, &plant[i].second);
            ys.push_back(plant[i].second);
        }
        vector<ii> vertex(m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &vertex[i].first, &vertex[i].second);
            ys.push_back(vertex[i].second);
        }

        sort(ys.begin(), ys.end());
        ys.resize( unique(ys.begin(), ys.end())-ys.begin() );
        compress(plant, ys, true);
        compress(vertex, ys);

        memset(bit, 0, sizeof bit);

        vector<iiii> events;
        for(int i = 0; i < m; i++) {
            if( vertex[i].first == vertex[(i+1)%m].first )
                events.push_back(iiii( ii(vertex[i].first, -1), ii(vertex[i].second, vertex[(i+1)%m].second) ));
        }
        for(int i = 0; i < n; i++) {
            events.push_back(iiii( ii(plant[i].first, i+1), ii(plant[i].second, -1) ));
        }

        sort(events.begin(), events.end());

        ll ans = 0;
        for(int i = 0; i < events.size(); i++) {
            iiii cur = events[i];
            if(cur.idx != -1) {
                if(!get(cur.y1))
                    ans += cur.idx;
            } else {
                update_range(cur.y1, cur.y2);
            }
        }

        printf("%lld\n", ans);
    }


}

