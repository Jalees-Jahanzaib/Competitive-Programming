#include<bits/stdc++.h>

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

int cases;

int get_hp(double IV, double Bs, double EV, double L) {
    return ((IV + Bs + double(sqrt(EV))/8.0+50.0)*L)/50.0 + 10.0;
}

int get_o(double IV, double Bs, double EV, double L) {
    return ((IV + Bs + double(sqrt(EV))/8.0)*L)/50.0 + 5.0;
}

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        string name; cin >> name;
        int level; cin >> level;
        cout << "Caso #" << ++cases << ": " << name << " nivel " << level << "\n";
        int bs, iv, ev;
        cin >> bs >> iv >> ev;
        cout << "HP: " << get_hp(iv, bs, ev, level) << "\n";
        cin >> bs >> iv >> ev;
        cout << "AT: " << get_o(iv, bs, ev, level) << "\n";
        cin >> bs >> iv >> ev;
        cout << "DF: " << get_o(iv, bs, ev, level) << "\n";
        cin >> bs >> iv >> ev;
        cout << "SP: " << get_o(iv, bs, ev, level) << "\n";

    }

}
