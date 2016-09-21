#include<bits/stdc++.h>

using namespace std;

int extended_euclid( int a, int b, int& x, int& y ) {
    int xx = y = 0;
    int yy = x = 1;
    while( b ) {
        int q = a/b;
        int t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

int mod_inverse( int a, int n ) {
    int x, y;
    int g = extended_euclid( a, n, x, y );
    if( g > 1 ) {
        return -1;
    }
    return ( x%n + n )%n;
}

/// computes x and y such that ax + by = c; on failure, x = y =-1
bool linear_diophantine( int a, int b, int c, int &x, int &y ) {
    int d = __gcd( a, b );
    if( c%d ) return false;
    else {
        x = c/d*mod_inverse( a/d, b/d );
        y = ( c-a*x )/b;
    }
    return true;
}

int main( ) {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;

    while( cin >> n ) {
        vector<int> rho( n ), alpha( n ), beta( n );
        for( int i = 0; i < n; i++ ) {
            cin >> rho[ i ] >> alpha[ i ] >> beta[ i ];
        }
        int ans = INT_MAX;
        for( int i = 0; i < n; i++ ) {
            for( int j = i+1; j < n; j++ ) {
                int a = alpha[ i ]-alpha[ j ];
                int b = beta[ j ]-beta[ i ];
                int k, t;
                if(!linear_diophantine(b, 360, a, t, k)) continue;
                int next = 360/__gcd(abs(b), 360);
                t = (t%next + next)%next;
                ans = min(t, ans);
            }
        }
        if( ans == INT_MAX ) {
            cout << "GIANIK IS NEVER ECLIPSED\n";
        }
        else {
            cout << ans << "\n";
        }
    }

  return 0;
}
