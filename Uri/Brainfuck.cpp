#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int cases;
queue<char> input;
char all[200000];

void go(string command, int &pointer, bool init) {
    if(int(command.size()) == 0) return;
    while(true) {
        for(int i = 0; i < command.size(); i++) {
            char c = command[i];
            if(c == '>') {
                pointer++;
            }
            if(c == '<') {
                pointer--;
            }
            if(c == '+') {
                all[pointer]++;
            }
            if(c == '-') {
                all[pointer]--;
            }
            if(c == '.') {
                cout << char(all[pointer]);
            }
            if(c == ',') {
                if(input.empty())
                    all[pointer] = 0;
                else {
                    all[pointer] = input.front();
                    input.pop();
                }
            }
            if(c == '[') {
                string cycle = "";
                ++i;
                while(command[i] != ']' && i < command.size()) cycle.push_back(command[i]), ++i;
                if(all[pointer] != 0)
                    go(cycle, pointer, false);
            }
            if(c == '#') {
                for(int j = 0; j < 10; j++) {
                    cout << char(all[j]);
                }
            }
        }
        if(init || all[pointer] == 0) break;
    }

}


int main() {
//    freopen("input.txt", "r", stdin);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string line; getline(cin, line); getline(cin, line);
        while(!input.empty()) input.pop();
        for(int i = 0; i < line.size(); i++) input.push(line[i]);
        memset(all, 0, sizeof all);
        string command; getline(cin, command);
        cout << "Instancia " << ++cases << "\n";
        int pointer = 0;
        go(command, pointer, true);
        cout << "\n";
        cout << "\n";
    }

}
