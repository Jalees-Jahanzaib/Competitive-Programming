#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline double sqr(double x) { return x*x; }

int main() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);

    vector<int> all = {0, 1, 2};
    vector< vector<double> > m( 3, vector<double>(3) );
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> m[i][j];
    double best = 0.0;
    do {
        best = max(best, sqrt( sqr(m[0][ all[0] ]) + sqr(m[1][ all[1] ]) + sqr(m[2][ all[2] ]) ) );
    } while( next_permutation(all.begin(), all.end()) );

    cout << fixed << setprecision(16) << best << "\n";

}
