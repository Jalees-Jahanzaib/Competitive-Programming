#include<bits/stdc++.h>

#define x first
#define y second
#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 10000;
const int limit = 4e8;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

vector<ii> v;

int last_upper(int y, int n) {
    for(int i = n-1; i >= 0; i--) {
        if(v[i].y > y)
            return i;
    }
    return -1;
}

int last_lower(int y, int n) {
    for(int i = n-1; i >= 0; i--) {
        if(v[i].y < y)
            return i;
    }
    return -1;
}

int upper(int y, int n, int limit) {
    for(int i = n-1; i >= 0; i--) {
        if(v[i].y < y && v[i].y > limit)
            return i;
    }
    return -1;
}

int lower(int y, int n, int limit) {
    for(int i = n-1; i >= 0; i--) {
        if(v[i].y > y && v[i].y < limit)
            return i;
    }
    return -1;
}

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n) {
        v = vector<ii> (n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y;
        }

        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int limit = v[i].y;
            int begin_upper = last_upper(v[i].y, i);
            while(begin_upper != -1) {
                ++ans;
                begin_upper = upper(v[begin_upper].y, begin_upper, limit);
            }
            int begin_lower = last_lower(v[i].y, i);
            while(begin_lower != -1) {
                ++ans;
                begin_lower = lower(v[begin_lower].y, begin_lower, limit);
            }
        }

        cout << ans << "\n";
    }

}
