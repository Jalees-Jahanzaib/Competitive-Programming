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
    trie* next[26];
    int open, word;
    char c;

    trie(char c) : open(0), word(0), c(c) {
        for(int i = 0; i < 26; i++) next[i] = NULL;
    }

    void add(string word) {
        trie* cur = this;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            if(cur->next[id] == NULL) cur->next[id] = new trie(word[i]), cur->open++;
            //cout << cur->c << " open = " << cur->open << " word = " << cur->word << endl;
            cur = cur->next[id];
        }
        cur->word++;
    }

    int get(string word) {
        trie* cur = this;
        int ans = 1;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            cur = cur->next[id];
            if( (cur->word && cur->open) || cur->open >= 2 ) ans++;
            //cout << cur->c << " open = " << cur->open << " word = " << cur->word << " " << ans << endl;
            //cout << ans << endl;
        }
        if(cur->word && cur->open) ans--;
        return ans;
    }
};

void del(trie* cur) {
    for(int i = 0; i < 26; i++)
        if(cur->next[i] != NULL)
            del(cur->next[i]);
    free(cur);
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(cin >> n) {
        trie *tree = new trie('-');
        vector<string> word(n);
        for(int i = 0; i < n; i++) {
            cin >> word[i];
            tree->add(word[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += tree->get(word[i]);
            //cout << tree->get(word[i]) << endl;
        }
        cout << fixed << setprecision(2) << double(sum)/(double(word.size())) << "\n";
        del(tree);
    }


}
