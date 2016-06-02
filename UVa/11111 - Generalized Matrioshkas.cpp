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
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ll long long
#define dd pair<double, double>
#define ii pair<double, int>
#define PB push_back
#define checkk x_ >= 0 && y_ >= 0 && x_ < R && y_ < C && !seen[x_][y_]
#define MAX 10000 + 10
#define INF INT_MAX / 5
#define EPS 1e-8
#define gauss(z) (ll)(z)*((z) + 1) / 2

using namespace std;

vector<int> v;

bool check(int left, int right, int value) {
    if(left == right) return false;
    int ans = 0;
    for(int i = left; i <= right; i++) {
        if(v[i] < 0) {
            for(int j = i; j <= right; j++) {
                if(v[i] + v[j] == 0) {
                    ans += abs(v[j]);
                    i = j;
                    break;
                }
                else if(j == right) return false;
            }
        }
    }

    return ans < value;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int a;
    string line;
    while(getline(cin, line)) {
        v.clear();

        int cant = 0;
        bool ok = true;
        istringstream ss(line);
        while(ss >> a) {
            v.PB(a);
            cant += (a < 0 ? 1 : -1);
            if(cant < 0) ok = false;
        }

        for(int i = 0; i < v.size(); i++) {
            if(v[i] < 0)
                for(int j = i; j < v.size(); j++) {
                    if(v[i] + v[j] == 0) {
                        ok &= check(i + 1, j - 1, abs(v[j]));
                        break;
                    }
                    else if(j == v.size() - 1) ok = false;
                }
        }

        if(ok && !cant) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";

    }
}
