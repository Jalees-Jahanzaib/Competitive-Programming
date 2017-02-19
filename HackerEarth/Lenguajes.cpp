#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 300010;
const ll MOD = 1e9 + 7;

int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};

int cases;

string vowel = "aiyeou";
string consonant = "bkxznhdcwgpvjqtsrlmf";

char look_for(char p) {
    char x = tolower(p);
    int pos = vowel.find(x);
    if(pos == -1) {
        pos = consonant.find(x);
        pos = ((pos-10)+int(consonant.size()))%int(consonant.size());
        return consonant[pos];
    } else {
        pos = ((pos-3)+int(vowel.size()))%int(vowel.size());
        return vowel[pos];
    }
}

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    string line;
    while(getline(cin, line)) {
        for(int i = 0; i < line.size(); i++) {
            if(line[i] >= 'A' && line[i] <= 'Z') {
                char x = look_for(line[i]);
                x = toupper(x);
                cout << x;

            } else if(line[i] >= 'a' && line[i] <= 'z') {
                char x = look_for(line[i]);
                cout << x;
            } else {
                cout << line[i];
            }
        }
        cout << "\n";
    }

}
