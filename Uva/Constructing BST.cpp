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
    return ceil(log2((end - start + 1) + 1)) <= height;
}

inline void solve(int start, int end, int h) {
    if(end < start) return;
    if(start == end){
        cout << " " << start;
        return;
    }

    for(int i = start; i <= end; i++)
        if(can(start, i - 1, h - 1) && can(i + 1, end, h - 1)) {
            cout << " " << i;
            solve(start, i - 1, h - 1); solve(i + 1, end, h - 1);
            return;
        }
}

int n, h, cases;

int main() {
    while(cin >> n >> h && h != 0 && n != 0) {
        cout << "Case " << ++cases << ":";
        if(!can(1, n, h)) cout << " Impossible.";
        else solve(1,n, h);
        cout << "\n";
    }
}
