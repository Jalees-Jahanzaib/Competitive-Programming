#include<bits/stdc++.h>

#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

using namespace std;

typedef double lf;
typedef complex<lf> pt;
typedef pair<lf, lf> dd;
typedef pair<dd, dd> line
;
const lf PI = acos(-1);
const lf EPS = 1e-10;

#define cross(A,B)		imag(conj((A))*(B))
#define dot(A,B)		real(conj((A))*(B))

int cmp ( lf A, lf B ) { return ( A+EPS < B ? -1 : ( B+EPS < A ? 1 : 0 ) ); }
bool helper ( pt A, pt B, pt P ) { return cmp ( dot ( A-P, B-P ), 0 ) <= 0; }
int sign ( lf p ) { return cmp(p,0); }
lf dist ( pt A, pt B ) { return abs(A-B); }

bool segTouch ( pt A, pt B, pt C, pt D ) {
	if ( cmp ( cross(B-A,D-C), 0 ) == 0 ) {
		if ( cmp ( cross(B-A,C-A), 0 ) != 0 )
			return false;
		return helper ( A, B, C )
		    || helper ( A, B, D )
		    || helper ( C, D, A )
		    || helper ( C, D, B );
	}
	return sign(cross(B-A,C-A))*sign(cross(B-A,D-A)) != 1
	    && sign(cross(D-C,A-C))*sign(cross(D-C,B-C)) != 1;
}

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    while(cin >> n && n) {
        dd cur = dd(0, 0);
        lf angle = PI/2.0;
        vector<line> all;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            lf a, d; cin >> a >> d;
            angle += a*PI/180.0;
            if(angle < 0) angle += 2.0*PI;
            if(angle > 2.0*PI) angle -= 2.0*PI;
            dd next = dd( cur.first + cos(angle)*d, cur.second + sin(angle)*d);
            all.push_back(line(cur, next));
            cur = next;
            bool ok = true;
            for(int j = i-2; j >= 0; j--) {
                ok &= !segTouch(pt(all[i].x1, all[i].y1), pt(all[i].x2, all[i].y2),
                                pt(all[j].x1, all[j].y1), pt(all[j].x2, all[j].y2) );
            }
            if(!ok && ans == -1) ans = i;
        }

        if(ans == -1) cout << "SAFE\n";
        else cout << ans+1 << "\n";
    }
}
