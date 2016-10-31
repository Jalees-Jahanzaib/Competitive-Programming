#include<bits/stdc++.h>

using namespace std;

const int MAX = 1010;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    string ans = "";
    while(getline(cin, line) && line != "#") {
        for(int i = 0; i < line.size(); i++) {
             if(( line[i] >= 'a' && line[i] <= 'z' ) || ( line[i] >= 'A' && line[i] <= 'Z' ) || line[i] == ' ')
                ans.push_back(line[i]);
             if(line[i] == '-' && i == int(line.size()) - 1)
                ans.push_back(line[i]);
        }
        ans.push_back('\n');
    }

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == '-') {
            ans.erase(ans.begin() + i);
            ans.erase(ans.begin() + i);
            int j = i;
            while(ans[j] != ' ' && ans[j] != '\n') j++;
            ans.insert(ans.begin() + j, '\n');
            j = i;
            while(ans[j] != ' ' && ans[j] != '\n') j--;
            j++;
            ans.insert(ans.begin() + j, '\n');
        }
    }
    cout << ans;

    return 0;
}
