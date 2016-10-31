#include<bits/stdc++.h>

using namespace std;

int main() {
    string line;
    cin >> line;
    string reversed = line;
    reverse(reversed.begin(), reversed.end());
    int n = line.size();

    cout << line << "\n";
    for(int i = 1; i < n-1; i++) {
        cout << reversed[i] << string(n - 2, ' ') << line[i] << "\n";
    }
    cout << reversed << "\n";
}
