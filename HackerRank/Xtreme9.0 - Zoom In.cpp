#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = INT_MAX;
const int MAX = 110;

const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};

unordered_map<char, vector<string>> all;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> m >> n >> k;
    cin.ignore();

    while(k--) {
        string line;
        char letter; getline(cin, line);
        letter = line[0];
        for(int i = 0; i < n; i++) {
            string word; getline(cin, word);
            all[letter].push_back(word);
        }
    }

    cin >> k;
    cin.ignore();
    while(k--) {
        string word; getline(cin, word);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < word.size(); j++) {
                cout << all[ word[j] ][i];
            }
            cout << "\n";
        }
    }



}
