#include<bits/stdc++.h>

#define ll unsigned long long
#define ii pair<long double, long double>
#define PB push_back
#define MAX 310
#define MAXLOG 15
#define INF 1LL<<60
#define MOD (987654321LL)
#define PI acos(-1)
#define EPS (long double)(1e-12);

using namespace std;

struct trie {
    trie* next[10];
    int open, word;
    char c;

    trie(char c) : open(0), word(0), c(c) {
        for(int i = 0; i < 10; i++) next[i] = NULL;
    }

    void add(string word) {
        trie* cur = this;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'0';
            if(cur->next[id] == NULL) cur->next[id] = new trie(word[i]), cur->open++;
            //cout << cur->c << " open = " << cur->open << " word = " << cur->word << endl;
            cur = cur->next[id];
        }
        cur->word++;
    }

};

bool go(trie* cur) {
    for(int i = 0; i < 10; i++)
        if(cur->next[i] != NULL)
            if(go(cur->next[i]))
                return true;
    return cur->word && cur->open;
}

void del(trie* cur) {
    for(int i = 0; i < 10; i++)
        if(cur->next[i] != NULL)
            del(cur->next[i]);
    free(cur);
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        trie *tree = new trie('-');
        string word;
        for(int i = 0; i < n; i++) {
            cin >> word;
            tree->add(word);
        }
        bool ok = go(tree);
        if(ok) cout << "NO\n";
        else cout << "YES\n";
        del(tree);
    }


}
