#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX int(1e5 + 10)
#define INF INT_MIN / 5;

using namespace std;

vector<int> v;
int a;
string line;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    while(getline(cin, line)) {
        v.clear();

        istringstream ss(line);
        while(ss >> a) v.PB(a);

        int maxi = 0, tmp = 0;
        for(int i = 0; i < v.size(); i++) {
            tmp += v[i];
            if(tmp < 0) tmp = 0;
            if(maxi < tmp) maxi = tmp;
        }

        cout << maxi << "\n";

    }


}
