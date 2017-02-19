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
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        printf("%02d:%02d - ", a, b);

        if(c) printf("A porta abriu!\n");
        else printf("A porta fechou!\n");
    }

}
