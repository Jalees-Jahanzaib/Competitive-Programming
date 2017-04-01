//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 60;
const double EPS = 1e-5;
const int INF = INT_MAX;
const ll MOD = int(1e9) + 7;

string board[MAX];
bool seen[MAX][MAX];

const int DX[] = {1, -1, 0, 0};
const int DY[] = {0, 0, 1, -1};

int n, m;

bool is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool is_number(char c) {
    return (c >= '0' && c <= '9');
}

bool is_mark(char c) {
    return !is_letter(c) && !is_number(c) && c != ' ';
}


int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

     string line;
     while(getline(cin, line) && line != "#") {
        bool ok = true;
        line = ' ' + line + ' ';
        int n = line.size();
//        cout << line << endl;
        for(int i = 1; i < n-1; i++) {
            if(is_upper(line[i])) {
                ok &= !is_upper(line[i-1]) && !is_upper(line[i+1]);
            }
            if(is_number(line[i])) {
                ok &= !is_letter(line[i-1]) && !is_letter(line[i+1]);
            }
            if(line[i-1] == ' ' && line[i+1] == ' ') {
                ok &= line[i] == 'A' || line[i] == 'I' || line[i] == 'a';
            }
            if(is_mark(line[i])) {
                if(is_mark(line[i-1])) ok &= line[i] == '"' || line[i-1] == '"';
                if(is_mark(line[i+1])) ok &= line[i] == '"' || line[i+1] == '"';
            }
//            if(!ok) {
//                cout << i << " " << line[i] << endl;
//                break;
//            }
        }

        if(ok) cout << "OK\n";
        else cout << "suspicious\n";

     }
}
