#include<bits/stdc++.h>

#define MOD			1000000021LL
#define MAX_N		100000

using namespace std;

typedef long long ll;
typedef long double lf;

const int MAX = 100010;
const lf gravity = 9.80665;
const lf PI = 3.14159;

lf sqr(lf x) {
    return x*x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double h, p1, p2, alpha, v0;
    while(cin >> h >> p1 >> p2 ) {
        int tries; cin >> tries;
        while(tries--) {
            cin >> alpha >> v0;
            alpha = alpha*PI/180.0;
            lf z = gravity*h/sqr(v0);
            lf time = (v0/gravity)*(sin(alpha) + sqrt( sqr(sin(alpha)) + 2*z ));
            lf x = v0*cos(alpha)*time;

            cout << fixed << setprecision(5) << x << " -> " << (x >= p1 && x <= p2 ? "DUCK" : "NUCK") << "\n";
        }

    }

}
