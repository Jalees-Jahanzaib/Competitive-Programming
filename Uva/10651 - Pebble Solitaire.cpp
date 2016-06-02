/* USER: 308958 (osdajigu) */
/* PROBLEM: 1592 (10651 - Pebble Solitaire) */
/* SUBMISSION: 14634730 */
/* SUBMISSION TIME: 2014-12-05 22:07:30 */
/* LANGUAGE: 3 */

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<utility>
#include<sstream>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define ll long long
#define PB push_back
#define MP make_pair
#define EPS 0.00000001
#define MAX 200 + 10
#define LIMIT 1000000
#define MOD 1000000007

using namespace std;
int nTest, ans, balls;
string board;

bool moveRight(int a, int b){
    if(b >= board.size()) return false;
    return (board[a] == 'o' && board[a + 1] == 'o' && board[b] == '-');
}
bool moveLeft(int a, int b) {
    if(b < 0) return false;
    return (board[a] == 'o' && board[a - 1] == 'o' && board[b] == '-');
}

int solve(int b) {
    string aux = board;
    for(int i = 0; i < board.size(); i++) {
        if(moveRight(i, i + 2)) {
            board[i] = '-';
            board[i + 1] = '-';
            board[i + 2]  = 'o';
            ans = min(ans, solve(b - 1));
            board = aux;
        }
        if(moveLeft(i, i - 2)) {
            board[i] = '-';
            board[i - 1] = '-';
            board[i - 2]  = 'o';
            ans = min(ans, solve(b - 1));
            board = aux;
        }
    }
    return min(ans, b);
}

int main() {
    cin >> nTest;
    while(nTest--) {
        ans = INT_MAX;
        cin >> board;
        balls = 0;
        for(int i = 0; i < board.size(); i++)
            if(board[i] == 'o')
                balls++;
        cout << solve(balls) << endl;
    }
}
