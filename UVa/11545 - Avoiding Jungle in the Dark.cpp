#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e5 + 10)
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

int T, cases;
string board;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    cin >> T;

    while(T-- > 0) {
        cin >> board;

        bool seen[1050][30][20], ok = false;
        memset(seen, false, sizeof seen);
        queue<int> q;
        q.push(0); q.push(6); q.push(0); q.push(0);

        seen[0][6][0] = true;
        while(!q.empty()) {
            int day = q.front(); q.pop();
            int hour = q.front(); q.pop();
            int ans = q.front(); q.pop();
            int walk = q.front(); q.pop();

            if(board[day] == 'D') {
                cout << "Case #" << ++cases << ": " << ans << "\n";
                ok = true;
                break;
            }

            if(walk <= 15) {
                int next = day + 1;
                int nhour = (hour + 1) % 24;
                int nans = ans + 1;
                int nwalk = walk + 1;
                if(!seen[next][nhour][nwalk]) {
                    if((nhour > 6 && nhour < 18 && board[next] == '*') || board[next] != '*'){
                        seen[next][nhour][nwalk] = true;
                        q.push(next);
                        q.push(nhour);
                        q.push(nans);
                        q.push(nwalk);
                    }
                }
            }

            int next = day;
            int nhour = (hour + 8) % 24;
            int nans = ans + 8;
            if(!seen[next][nhour][0]) {
                if((nhour > 6 && nhour < 18 && board[next] == '*') || board[next] != '*') {
                    seen[next][nhour][0] = true;
                    q.push(next);
                    q.push(nhour);
                    q.push(nans);
                    q.push(0);
                }
            }

        }

        if(!ok) {
            cout << "Case #" << ++cases << ": " << -1 << "\n";
        }

    }

}
