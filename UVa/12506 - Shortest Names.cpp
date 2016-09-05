    #include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 200010
#define INF 0x3fffffff
#define ll long long
#define MOD 1000000007

using namespace std;

struct trie {
    vector<trie*> next;
    int prefix;

    trie() : prefix(0), next(26, nullptr) {}

    void add(string word) {
        trie* cur = this;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            if(cur->next[id] == nullptr) cur->next[id] = new trie();
            cur = cur->next[id];
            cur->prefix++;
        }
    }

    int go(string word) {
        trie* cur = this;
        for(int i = 0; i < word.size(); i++) {
            cur = cur->next[ word[i]-'a' ];
            if(cur->prefix == 1) return i + 1;
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        trie* tree = new trie();
        vector<string> word(n);
        for(int i = 0; i < n; i++) {
            cin >> word[i];
            tree -> add(word[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += tree->go(word[i]);
        }
        cout << ans << "\n";
    }



}
