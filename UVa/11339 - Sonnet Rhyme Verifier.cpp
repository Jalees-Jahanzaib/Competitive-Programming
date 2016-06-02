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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    string tittle, aux, ans, line;
    vector<string> r;

    while(getline(cin, line)) {
        r.clear();
        ans = "";

        istringstream ss(line);
        while(ss >> aux) r.PB(aux);
        getline(cin, tittle);

        while(getline(cin, line) && line != "")  {
            string newLine = "";
            for(int i = 0; i < line.size(); i++) {
                if(int(line[i]) == -83 || line[i] == '!' || line[i] == ',' || line[i] == '.' || line[i] == ':' || line[i] == ';' || line[i] == '¿' || line[i] == '?' || line[i] == '-') continue;
                newLine += line[i];
            }

            int n = newLine.size();
            for(int i = newLine.size() - 1; i >= 0; i--)
                if(newLine[i] == ' ' || newLine[i] == 's') newLine.erase(newLine.end() - 1);
                else break;

            for(int k = 0; k < r.size(); k++) {
                bool found = false;
                int i = r[k].size() - 1, j = newLine.size() - 1;
                while(i >= 0 && j >= 0) {
                    if(r[k][i] != newLine[j]) break;
                    if(i == 0) found = true;
                    i--, j--;
                }
                if(found) {
                    ans += (k + 'A');
                    break;
                }
            }
        }

        if(ans.size() != 14) cout << tittle << ": Not a chance!\n";
        else {
            if(ans == "ABBAABBACDCDCD" || ans == "ABBAABBACDECDE" || ans == "ABBAABBACDEDCE" || ans == "ABBAABBACDCDCD") cout << tittle << ": " << ans << "\n";
            else cout << tittle << ": Not a chance!\n";
        }
    }
}
