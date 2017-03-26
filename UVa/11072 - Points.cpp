#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAX = 100005;
const int INF = INT_MAX/2;

typedef double lf;
typedef complex<lf> pt;
const lf PI = acos(-1);
const lf EPS = 1e-9;
#define x(P)		real(P)
#define y(P)		imag(P)
#define cross(A,B)		imag(conj((A))*(B))
int cmp ( lf A, lf B ) { return ( A+EPS < B ? -1 : ( B+EPS < A ? 1 : 0 ) ); }

pt p[MAX], ch[MAX];

bool cmpt(pt &p, pt &q) {
    if(x(p) != x(q)) return x(p) < x(q);
    return y(p) < y(q);
}

int orientation(pt &p, pt &q, pt &r) {
    return cmp(cross(q-p, r-p), 0); /// 0->colineal, 1->left, -1->right
}

int convex_hull(int n) {
    sort(p, p + n, cmpt);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        /// if colineal use < and remove repeated points
		while (k >= 2 && orientation(ch[k-2], ch[k-1], p[i]) <= 0)
            k--;
		ch[k++] = p[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && orientation(ch[k-2], ch[k-1], p[i]) <= 0)
            k--;
		ch[k++] = p[i];
	}
    return k-1;
}

istream& operator >> ( istream& in, pt& p ) {
  lf x,y; in >> x >> y;
  p = pt(x,y); return in;
}

int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // LOCAL

    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int k = convex_hull(n);

        cout << "k = " << k<< endl;

        for(int i = 0; i < k; i++) {
            cout << x(ch[i]) << " " << y(ch[i]) << endl;
        }

        int m; cin >> m;
        while(m--) {
            bool inside = true;
            pt x;
            cin >> x;
            for(int i = 0; i < k; i++) {
                if(orientation(ch[i], ch[(i+1)%k], x) < 0) {
                    inside = false;
                }
            }
            cout << (inside ? "inside" : "outside") << "\n";
        }
    }
}
