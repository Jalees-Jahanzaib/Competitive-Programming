#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<ll, ll> ii;
typedef pair<lf, ii> iii;

const int INF = INT_MAX;
const ll MAX = 200010;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

int n;
double A;

double geth(double hl, double hc) {
    return 2.0*hc+2.0-hl;
}

double B;

double can(double x) {
    double hl = A, hc = x;
    for(int i = 2; i < n; i++) {
        double hr = geth(hl, hc);
        if(hr < 0.0) return false;
        hl = hc;
        hc = hr;
    }
    B = hc;
    return true;
}

const double EPS = 1e-8;

bool first;

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(2);

    int t; cin >> t;
    while(t--) {
        if(first) cout << "\n";
        first = true;
        cin >> n >> A;
        double low = 0.0, high = 1e12;
        while(abs(high-low) > EPS) {
            double mid = (low+high)/2;
            if(can(mid)) high = mid;
            else low = mid;
        }

        cout << B << "\n";
    }


}


