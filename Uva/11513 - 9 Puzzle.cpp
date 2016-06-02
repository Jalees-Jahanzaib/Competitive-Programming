#include<bits/stdc++.h>

#define ii pair<string, string>

using namespace std;

string getV(string x, int pos) {
    char aux = x[pos + 6];
    x[pos + 6] = x[pos + 3];
    x[pos + 3] = x[pos];
    x[pos] = aux;
    return x;
}

string getH(string x, int pos) {
    char aux = x[pos];
    x[pos] = x[pos + 1];
    x[pos + 1] = x[pos + 2];
    x[pos + 2] = aux;
    return x;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, ii> seen;
    queue<string> q;
    q.push("123456789");
    seen["123456789"] = ii("-1", "-1");
    while(!q.empty()) {
        string u = q.front(); q.pop();

        for(int i = 0; i < 3; i++) {
            string v = getH(u, i*3);
            if(!seen.count(v)) {
                string p = "H";
                p += ('1' + i);
                seen[v] = ii(u, p);
                q.push(v);
            }

            v = getV(u, i);
            if(!seen.count(v)) {
                string p = "V";
                p += ('1' + i);
                seen[v] = ii(u, p);
                q.push(v);
            }
            //cout << v << endl;

        }
    }

    string line = "";
    char x;
    while(cin >> x && x != '0') {
        line = x;
        for(int i = 0; i < 3; i++)
            for(int j = (i == 0 ? 1 : 0); j < 3; j++) {
                cin >> x;
                line += x;
            }

        if(!seen.count(line)) {
            cout << "Not solvable\n";
            continue;
        }

        string u = line;
        vector<string> ans;
        while(u != "123456789") {
            ans.push_back(seen[u].second);
            u = seen[u].first;
        }

        cout << ans.size() << " ";
        for(int i = 0; i < ans.size(); i++) cout << ans[i]; cout << "\n";
    }
}
