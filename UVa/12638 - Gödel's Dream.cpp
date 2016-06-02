#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e2 * 5 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> s) {
        int ans = 0, miss = 0, zero = 0, solved = 0, lastSolved = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                lastSolved = 0;
                miss++;
                if(zero == 1 && miss) {
                    zero = 0, solved++;
                    if(solved > 1 && miss) miss--;
                }
            }
            if(s[i] == '?' || s[i] == '0') {
                if(miss) {///Pongo un 0
                    if(lastSolved > 0) {
                        miss--, solved++;
                    }
                    else if(zero == 1) { /// dos 0 seguidos, soluciono un 1
                        zero = 0, miss--, solved++, lastSolved++;
                        if(solved > 1 && miss) miss--;
                    }
                    else zero++;
                }
            }

            if(!miss) solved = 0, ans++;
        }

        if(miss) ans = 0;
        cout << ans << endl;
    }
}



