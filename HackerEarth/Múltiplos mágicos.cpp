#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 300010;
const ll MOD = 1e9 + 7;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

unordered_set<ll> all;

void doit(ll n) {
    while(n) {
        all.insert(n%10);
        n /= 10;
    }
}

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll n;
    while(cin >> n) {
        all.clear();
        ll k = 1;
        while(true) {
            doit(k*n);
            if(all.size() == 10) break;
            k++;
        }
        cout << k << "\n";
    }

}
