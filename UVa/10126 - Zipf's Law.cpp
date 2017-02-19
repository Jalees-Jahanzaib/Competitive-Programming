#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iiii;

const int INF = INT_MAX/4;
const int MAX = 70001;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int cases;
bool first = true;

int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    while(cin >> n) {
        if(!first) cout << "\n";
        first = false;
        map<string, ll> cnt;
        cin.ignore();
        string line;
        while(getline(cin, line) && line != "EndOfText") {
            string nline;
            for(int i = 0; i < line.size(); i++) {
                if( (line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
                    char c = tolower(line[i]);
                    nline.push_back(c);
                } else {
                    nline.push_back(' ');
                }
            }
            istringstream ss(nline);
//            cout << " -- " << nline << endl;
            string tmp;
            while(ss >> tmp) {
                cnt[tmp]++;
            }
        }
        bool ok = false;
        for(auto &x : cnt) {
            if(x.second == n) {
                cout << x.first << "\n";
                ok = true;
            }
        }

        if(!ok) {
            cout << "There is no such word.\n";
        }



    }

}

