#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 200010
#define INF 0x3fffffff
#define ll long long
#define MOD 1000000007

using namespace std;

struct trie{
    trie* next[26];
    int word;
    trie() : word(-1) {
        for(int i = 0; i < 26; i++) next[i] = NULL;
    }

    void add(string word, int id) {
        trie* cur = this;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i] - 'a';
            if(cur->next[id] == NULL) cur->next[id] = new trie();
            cur = cur->next[id];
        }
        cur->word = id;
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);



}
