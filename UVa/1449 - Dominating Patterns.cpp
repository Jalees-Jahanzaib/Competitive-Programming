#include <bits/stdc++.h>

#define PB push_back
#define is pair<int, string>
//#define MAX 500 + 10
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

struct State {
    int id, cnt;
    string pat;
    State(int id, int cnt, string pat) : id(id), cnt(cnt), pat(pat) {}

    bool operator < (const State &x) const {
        if(cnt != x.cnt) return cnt < x.cnt;
        return id > x.id;
    }
};

int phi[100], k;

int kmp(string &p, string &t) {
    int ans = 0;

    phi[0] = k = -1;
    for(int i = 1; i <= p.size(); i++) {
        while( k > -1 && p[k] != p[i-1]) k = phi[k];
        phi[i] = ++k;
    }

    k = 0;
    for(int i = 0; i < t.size(); i++) {
        while(k > -1 && p[k] != t[i]) k = phi[k];
        ++k;
        if(k == p.size()) ans++, k = phi[k];
    }

    return ans;

}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    /*cin.tie(0);
    cout.tie(0);/**/
    //freopen("output.txt", "w", stdout);
    string line;
    while(cin >> n && n != 0) {
        vector<State> v;
        for(int i = 0; i < n; i++) {
            cin >> line;
            v.PB(State(i, 0, line));
        }
        string t;
        cin >> t;

        for(int i = 0; i < n; i++) {
            string p = v[i].pat;
            v[i].cnt = kmp(p, t);
        }

        sort(v.rbegin(), v.rend());
        int maxi = v[0].cnt;
        cout << maxi << "\n";
        for(int i = 0; i < n; i++) {
            if(v[i].cnt == maxi) cout << v[i].pat << "\n";
        }
    }

}
