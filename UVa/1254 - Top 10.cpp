#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, int> ii;

struct cmp {
    bool operator() (const ii &a, const ii &b) const{
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
};

const int MAX_N = 10000;

string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t; }
	for (i = 0; i < n; i++)
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void buildSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
   tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;
	}
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    T = "AAAAAAAAAAAAAA$";
    string a ("AA");
    string b ("AAA");
    cout << (a.compare(b)) << endl;
    n = T.size();
    buildSA();

    for(int i = 0; i < T.size(); i++) {
        cout << SA[i] << " ";
        for(int j = SA[i]; j < T.size(); j++) {
            //cout << T[j];
        }
        cout << endl;
    }

//    int n; cin >> n;
//    vector<string> word(n);
//    vector<int> id;
//    string all = "";
//    int idx = 0;
//    for(int i = 0; i < n; i++) {
//        cin >> word[i];
//        for(int j = 0; j < word[i].size(); j++) {
//            all.push_back(word[i][j]);
//            id.push_back(idx);
//        }
//        all.push_back('#');
//        id.push_back(idx);
//        idx++;
//    }
//
//    int q; cin >> q;
//    string p;
//    while(q--) {
//        cin >> p;
//        set<ii, cmp> ans;
//        KMP(p, all, word, id, ans);
//        if(int(ans.size()) == 0) {
//            cout << "-1\n";
//        }
//        else {
//            set<ii, cmp>::iterator it = ans.begin();
//            for(int i = 0; i < 10 && it != ans.end(); it++, i++) {
//                 if(i) cout << " ";
//                cout << (*it).second + 1;
//            }
//            cout << "\n";
//        }
//    }
}
