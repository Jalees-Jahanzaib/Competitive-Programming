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

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string line; getline(cin, line);
        int g = 0, b = 0;
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == 'g' || line[i] == 'G') g++;
            if(line[i] == 'b' || line[i] == 'B') b++;
        }

        if(g > b) cout << line << " is GOOD\n";
        else if(g < b) cout << line << " is A BADDY\n";
        else cout << line << " is NEUTRAL\n";
    }

}
