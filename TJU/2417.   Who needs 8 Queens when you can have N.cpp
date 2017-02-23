#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 1000;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << n << "\n";
        vector<int> odd, even;
        for(int i = 1; i <= n; i += 2) {
            odd.push_back(i);
        }
        for(int i = 2; i <= n; i += 2) {
            even.push_back(i);
        }
        if(n%6 != 2 && n%6 != 3) {
            for(int i = 0; i < even.size(); i++) cout << even[i]-1 << "\n";
            for(int i = 0; i < odd.size(); i++) cout << odd[i]-1 << "\n";
        } else if(n%6 == 2){
            swap(odd[0], odd[1]);
            for(int i = 0; i < even.size(); i++) cout << even[i]-1 << "\n";
            for(int i = 0; i < odd.size(); i++) {
                if(i == 2) continue;
                cout << odd[i]-1 << "\n";
            }
            cout << 4 << "\n";
        } else {
            for(int i = 1; i < even.size(); i++) cout << even[i]-1 << "\n";
            cout << 1 << "\n";
            for(int i = 2; i < odd.size(); i++) {
                cout << odd[i]-1 << "\n";
            }
            cout << "0\n2\n";
        }
    }

}
