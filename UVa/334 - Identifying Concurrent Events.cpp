#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, string> ii;

const int MAX = 300;
unordered_map<int, string> rev_id;

int cases;

bool m[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0) {
        unordered_map<string, int> id;
        rev_id.clear();
        memset(m, false, sizeof m);
        int tag = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            for(int j = 0; j < x; j++) {
                string name; cin >> name;
                if(j) m[tag-1][tag] = true;
                id[name] = tag++;
                rev_id[tag-1] = name;
            }
        }

        cin >> n;
        for(int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            int na = id[a], nb = id[b];
            m[na][nb] = true;
        }
        for(int k = 0; k < tag; k++)
            for(int i = 0; i < tag; i++)
                for(int j = 0; j < tag; j++) {
                    if(m[i][k] && m[k][j])
                        m[i][j] = true;
                }

        set<ii> all;
        for(int i = 0; i < tag; i++) {
            for(int j = i+1; j < tag; j++) {
                if(!m[i][j] && !m[j][i]) {
                    string a = rev_id[i];
                    string b = rev_id[j];
                    all.insert( ii(a, b) );
                }
            }
        }
        cout << "Case " << ++cases << ", ";
        if(all.size() > 0) {
            cout << int(all.size()) << " concurrent events:\n";
            int i = 0;
            for(auto it = all.begin(); it != all.end() && i < 2; it++, i++) {
                cout << "(" << (*it).first << "," << (*it).second << ") ";
            }
            cout << "\n";
        } else {
            cout << "no concurrent events.\n";
        }

    }

}
