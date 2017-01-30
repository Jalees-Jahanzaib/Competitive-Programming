#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("chairs.in", "r", stdin);
    freopen("chairs.out", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;
    a /= 2.0;
    b /= 2.0;
    c /= 2.0;
    cout << fixed << setprecision(8) << (a+b+c)/3.0 << "\n";

}
