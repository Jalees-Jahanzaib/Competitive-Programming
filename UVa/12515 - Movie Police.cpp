#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 1000 + 10
#define INF INT_MAX / 4
#define ll long long
#define LEFT 1
#define RIGHT 2
#define gauss(x) (x)*(x+1)/2

using namespace std;

string movie[MAX], clip;
int n, q;

int main () {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(cin >> n >> q) {
        for(int i = 0; i < n; i++) cin >> movie[i];

        while(q--) {
            cin >> clip;

            int bestIndex = int(1e6), bestAmount = -1;
            for(int i = 0; i < n; i++) {
                int curAmount = 0;
                for(int j = 0; j <= (int)(movie[i].size() - clip.size()); j++) {
                    int cur = 0;
                    for(int k = 0; k < clip.size(); k++)
                        if(movie[i][k + j] == clip[k]) cur++;
                    curAmount = max(curAmount, cur);
                }

                if(bestAmount < curAmount) {
                    bestAmount = curAmount;
                    bestIndex = i + 1;
                }
                else if(bestAmount == curAmount && bestIndex > i + 1) {
                    bestIndex = i + 1;
                }
            }

            cout << bestIndex << "\n";
        }
    }

}
