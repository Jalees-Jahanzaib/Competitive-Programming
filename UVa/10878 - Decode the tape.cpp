#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string line;
	getline(cin, line);
	while(getline(cin, line)) {
		int ans = 0;
		for(int i = line.size() - 1, j = -1; i >= 0; i--, j++) {
			if(line[i] == 'o') ans |= (1<<j);
			if(line[i] == '.') j--;
		}
		cout << char(ans);
		if(line[1] == '_') break;
	}
}
