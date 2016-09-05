#include <bits/stdc++.h>

#define PB push_back
#define ii pair< ll, ll >
#define state pair< int, ii >
#define MAX 100010
#define INF lf(1e18)
#define ll long long
#define MOD 1000000007

using namespace std;

ll fact[20];
vector<int> cnt;

ll get(int k, int n) {
    ll ans = fact[n];
    for(int i = 0; i < 26; i++)
        ans /= k == i ? fact[ cnt[i]-1 ] : fact[ cnt[i] ];
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    fact[0] = 1ll;
    for(ll i = 1; i < 20; i++)
        fact[i] = i*fact[i-1];


    ll n; string line;
    while(cin >> line >> n && line != "#") {
        cnt = vector<int> (26);
        for(int i = 0; i < line.size(); i++) cnt[ line[i] - 'A' ]++;
        int all = line.size();
        while(all) {
            ll cur = 0, last = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt[i]) {
                    ll tmp = get(i, all-1);
                    if(cur + tmp >= n) {
                        cout << char(i + 'A');
                        cnt[i]--;
                        all--;
                        n = n - last;
                        break;
                    }
                    cur += tmp;
                    last = cur;
                }
            }
        }
        cout << "\n";

    }

}
