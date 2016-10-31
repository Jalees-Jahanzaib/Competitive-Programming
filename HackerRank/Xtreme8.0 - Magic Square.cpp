#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = INT_MAX;
const int MAX = 610;

int board[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int diagonal = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(i == j) diagonal += board[i][j];
        }
    }

    vector<int> all;
    for(int i = n-1; i >= 0; i--) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += board[j][i];
        }
        if(sum != diagonal) all.push_back(-(i+1));
    }
    int sum = 0;
    for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) sum += board[i][j];
    if(sum != diagonal) all.push_back(0);

    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            sum += board[i][j];
        }
        if(sum != diagonal) all.push_back((i+1));
    }

    cout << int(all.size()) << "\n";
    for(int i = 0; i < all.size(); i++) {
        cout << all[i] << "\n";
    }



}
