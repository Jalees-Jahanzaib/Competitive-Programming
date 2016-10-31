#include<bits/stdc++.h>

using namespace std;

typedef double lf;
typedef complex<lf> pt;
const lf EPS = 1e-10;

#define cross(A,B)		imag(conj((A))*(B))
#define dot(A,B)		real(conj((A))*(B))
int cmp ( lf A, lf B ) { return ( A+EPS < B ? -1 : ( B+EPS < A ? 1 : 0 ) ); }

bool pointInTriangle ( pt A, pt B, pt C, pt P ) {
    return cmp ( abs(cross(B-A,C-A)),
        abs(cross(A-P,B-P)) +
        abs(cross(B-P,C-P)) +
        abs(cross(C-P,A-P)) ) == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b, r;
        cin >> a >> b >> r;
        vector<pt> point;
        for(int x = a+r; x >= a-r; x--) {
            for(int y = b+r; y >= b-r; y--) {
                if((x-a)*(x-a) + (y-b)*(y-b) == r*r) {
                    point.push_back(pt(x, y));
                }
            }
        }
        int ans = 0;
        int n = point.size();
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                for(int k = j+1; k < n; k++) {
                    if(pointInTriangle(point[i], point[j], point[k], pt(a, b)))
                        ans++;
                }

        cout << n << " " << ans << "\n";
    }
}
