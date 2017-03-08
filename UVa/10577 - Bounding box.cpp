#include<bits/stdc++.h>

using namespace std;

typedef double lf;
typedef complex<lf> pt;
const lf PI = acos(-1);
const lf EPS = 1e-10;
#define cross(A,B)		imag(conj((A))*(B))
#define dot(A,B)		real(conj((A))*(B))
int cmp ( lf A, lf B ) { return ( A+EPS < B ? -1 : ( B+EPS < A ? 1 : 0 ) ); }

pt midPoint ( pt A, pt B ) { return ( A+B)/2.0; }
pt rotate90CCW ( pt A ) { return A * pt(0,1); }
pt linesIntersection ( pt A, pt B, pt C, pt D ) {
	lf s = cross ( C-A, D-C ) / cross ( B-A, D-C );
	return A + (B-A)*s;
}
pt rotate( pt A, lf ang ) { return A * exp ( ang * pt(0,1) ); }
pt rotateRB(pt A, pt B, lf ang) { return rotate(A-B, ang) + B; }


istream& operator >> ( istream& in, pt& p ) {
    lf x,y; in >> x >> y;
    p = pt(x,y); return in;
}

int cases;

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

    cout << fixed << setprecision(3);

    int n;
    while(cin >> n && n) {
        pt a, b, c;
        cin >> a >> b >> c;
        pt mab = midPoint(a, b);
        pt mac = midPoint(a, c);
        pt rmab = rotateRB(a, mab, PI/2);
        pt rmac = rotateRB(c, mac, PI/2);

        pt inter = linesIntersection(mab, rmab, mac, rmac);

        pt init = a;
        lf mxx = real(a), mxy = imag(a), mnx = real(a), mny = imag(a);
        for(int i = 0; i < n-1; i++) {
            init = rotateRB(init, inter, (2*PI)/n);
            mxx = max(mxx, real(init));
            mxy = max(mxy, imag(init));
            mnx = min(mnx, real(init));
            mny = min(mny, imag(init));
        }

        cout << "Polygon " << ++cases << ": " << (mxx-mnx)*(mxy-mny) << "\n";

    }
}
