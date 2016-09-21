#include<bits/stdc++.h>

using namespace std;

const int MAX = 105;
const double INF = 1e12;

typedef double lf;
typedef complex<lf> pt;

#define cross(A,B)		imag(conj((A))*(B))
#define dot(A,B)		real(conj((A))*(B))

lf dist ( pt A, pt B ) { return abs(A-B); }
lf distToLine ( pt A, pt B, pt P ) {
    if(dot(B-A, P-B) > 0) return dist(B, P);
    if(dot(A-B, P-A) > 0) return dist(A, P);
    return abs ( cross(A-P,B-P) / (B-A) );
}

pt all[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(3);

    string line;
    while(cin >> line && line != "*") {
        istringstream ss(line);
        int n; ss >> n;

        double x, y;
        cin >> x >> y;
        pt center(x, y);

        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            all[i] = pt(x, y);
        }

        double ans = INF;
        for(int i = 0; i < n; i++) {
            ans = min(ans, distToLine(all[i], all[(i+1)%n], center));
        }

        cout << ans << "\n";
    }

}
