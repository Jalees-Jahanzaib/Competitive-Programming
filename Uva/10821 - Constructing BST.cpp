/* USER: 308958 (osdajigu) */
/* PROBLEM: 1762 (10821 - Constructing BST) */
/* SUBMISSION: 15352677 */
/* SUBMISSION TIME: 2015-04-19 23:32:49 */
/* LANGUAGE: 3 */

#include<iostream>
#include<math.h>
#include<set>
#include<vector>
#include<queue>

#define ii pair<int, int>
#define PB push_back
#define check x >= 0 && y >= 0 && x < R && y < C && !board[x][y]

using namespace std;

int nTest;

inline bool can(int start, int end, int height) {
    return ceil(log2((end - start + 1)*1.0 + 1.0)) <= height;
}

vector<int> ans;

void print() {
    cout << "vector -> ";
    for(int i = 0; i < ans.size(); i++)
        if(i) cout << " " << ans[i];
        else cout << ans[i];
    cout << "\n";
}

//int prof = 0;

bool solve(int start, int end, int h) {
    if(start == end) return true;
    if(can(start, start, h - 1) && can(start + 1, end, h - 1)) {
        ans.PB(start);
        if(start + 1 == end) ans.PB(start + 1);
        solve(start, start, h - 1); solve(start + 1, end, h - 1);
        return true;
    }

    for(int i = start + 1; i <= end - 1; i++) {
        if(can(start, i - 1, h - 1) && can(i + 1, end, h - 1)) {
            ans.PB(i);
            if(start == i - 1) ans.PB(start);
            if(end == i + 1) ans.PB(end);
            solve(start, i - 1, h - 1); solve(i + 1, end, h - 1);
            return true;
        }
    }

    if(can(end, end, h - 1) && can(start, end - 1, h - 1)) {
        ans.PB(end);
        if(end - 1 == start) ans.PB(start);
        solve(end, end, h - 1); solve(start, end - 1, h - 1);
        return true;
    }
    return false;
}

int n, h, cases;

int main() {

    while(cin >> n >> h && h != 0 && n != 0){
        cout << "Case " << ++cases << ": ";
        ans.clear();
        if(!can(1, n, h)) cout << "Impossible.\n";
        else {
            if(!solve(1,n, h)) cout << "Impossible.\n";
            else {
                for(int i = 0; i < ans.size(); i++) {
                    if(i) cout << " " << ans[i];
                    else cout << ans[i];
                }
                cout << "\n";
            }
        }
    }
}
