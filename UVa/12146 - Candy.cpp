#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 100 + 10
#define INF INT_MAX / 3
#define ll long long
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin)

    int R, C, f, first, second, s, aux, tmp;
    while(cin >> R >> C && (R + C) != 0) {

        f = 0; s = 0;
        for(int i = 0; i < R; i++) {
            first = 0; second = 0;
            for(int j = 0; j < C; j++) {
                cin >> aux;
                tmp = second;
                second = max(second, first + aux);
                first = tmp;
            }
            second = max(second, first);
            tmp = s;
            s = max(s, f + second);
            f = tmp;
        }

        s = max(f, s);

        cout << s << "\n";

    }
}
