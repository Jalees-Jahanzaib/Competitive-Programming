    #include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 200010
#define INF 0x3fffffff
#define ll long long
#define MOD 1000000007

using namespace std;

struct trie {
    trie* next[2];
    int prefix;
    trie() : prefix(0) {
        for(int i = 0; i < 2; i++) next[i] = NULL;
    }

    int add(string word) {
        trie* cur = this;
        int ans = 0;
        for(int i = 0; i < word.size(); i++) {
            int id = word[i] - '0';
            if(cur->next[id] == NULL) cur->next[id] = new trie();
            cur = cur->next[id];
            cur->prefix++;
            ans = max(cur->prefix*(i+1), ans);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        trie* tree = new trie();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            string line; cin >> line;
            ans = max(ans, tree->add(line) );
        }
        cout << ans << "\n";
    }



}
