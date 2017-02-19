#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, char> iii;

const int INF = INT_MAX;
const int MAX = 10000;
const int limit = 4e8;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {1, 3, 5, 10, 25, 50, 100};

    int n; cin >> n;

    cout << "Top " <<  *lower_bound(a.begin(), a.end(), n) << "\n";

}
