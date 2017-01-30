#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

unordered_map<char, ii> all;

int get_dist(char a, char b) {
    return max( abs(all[a].first - all[b].first), abs(all[a].second - all[b].second) );
}

int main() {
    freopen("template.in", "r", stdin);
    freopen("template.out", "w", stdout);

    int n, m; cin >> m >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        string line; getline(cin, line);
        for(int j = 0; j < m; j++) {
            all[ line[j] ] = ii(j, n-i-1);
        }
    }

    string line;
    getline(cin, line);
    string name_best = "";
    int best = INT_MAX;
    for(int times = 0; times < 3; times++) {
        string name; getline(cin, name);
        string super_line = "", line;
        while(getline(cin, line) && line != "") {
            super_line += line;
        }

        int cur = 0;
        for(int i = 1; i < super_line.size(); i++) {
            cur += get_dist(super_line[i], super_line[i-1]);
        }
        if(cur < best) {
            best = cur;
            name_best = name;
        }
    }

    cout << name_best << "\n" << best << "\n";

}
