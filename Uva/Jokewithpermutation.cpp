//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define PB push_back
using namespace std;

string s;
vector<int> ans;
bool seen[200];
int MAX;

int toInt(string m) {
    return m.size() == 1 ? m[0] - '0' : (m[0] - '0') * 10 + (m[1] - '0');
}

void print() {
    for(int i = 0; i < ans.size(); i++) {
        if(!i) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << "\n";
}

bool solve(int index) {
    print();
    if(index >= s.size() && ans.size() == MAX) {
        /*vector<int> aux (ans.begin(), ans.end());
        sort(aux.begin(), aux.end());
        for(int i = 0; i < aux.size(); i++)
            if(aux[i] != i + 1) return false;
        print();*/
        return true;
    }
    for(int i = index; i < s.size(); i++) {
        int n = toInt(s.substr(i, 2));
        if(n <= MAX) {
            if(!seen[n]) {
                ans.PB(n); seen[n] = true;
                if(solve(i + 2)) return true;
                ans.pop_back(); seen[n] = false;
            }
        }
        if(n / 10 != 0) {
            if(!seen[n / 10]) {
                ans.PB(n / 10); seen[n / 10] = true;
                if(solve(i + 1)) return true;
                ans.pop_back(); seen[n / 10] = false;
            }
        }
        return false;
    }
    return false;

}

int main() {
    while(getline(cin, s)) {
        memset(seen, false, sizeof seen);
        ans.clear();
        MAX = (s.size() > 9 ? 9 + (s.size() - 9) / 2 : s.size());
        solve(0);
    }

}
