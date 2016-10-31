#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = INT_MAX;
const int MAX = 1010;

const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

char id(int x) {
    if(x <= 9) return x + '0';
    if(x <= 35) return (x - 10) + 'a';
    return (x - 36) + 'A';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string base; cin >> base;
    int q; cin >> q;
    while(q--) {
        string target; cin >> target;
        string base_url = base;
        while(base_url.size() < target.size()) {
            base_url += base;
        }

        base_url.resize( target.size() );
        long long number = 0;
        for(int i = int(target.size()) - 1, j = 0; j < 8; j++, i-- ) {
            number += ((long long)((int)(base_url[i])^(int)(target[i])))<<(8*j);
        }

        string base62 = "";
        while(number) {
            base62.push_back( id(number%62) );
            number /= 62;
        }
        reverse(base62.begin(), base62.end());

        cout << base + "/" + base62 << "\n";

    }

}
