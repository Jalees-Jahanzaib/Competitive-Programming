#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iiii;

const int INF = INT_MAX/4;
const int MAX = 70001;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int cases;

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cin.ignore();
        if(cases) cout << "\n";
        cout << "Case " << ++cases << ":\n";
        for(int i = 0; i < n; i++) {
            string line, tmp; getline(cin, line);
//            cout << line << endl;
            bool ok = false;
            for(int i = 0; i < line.size(); i++) {
                if(line[i] == ' ') {
                    if(!ok)
                        tmp.push_back(line[i]);
                    ok = true;
                } else {
                    ok = false;
                    tmp.push_back(line[i]);
                }
            }
            cout << tmp << "\n";
        }

    }


}
