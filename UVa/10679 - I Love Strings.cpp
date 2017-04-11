#include<bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

const int MAX = 100005;
const double EPS = 1e-5;
const int INF = INT_MAX;
const ll MOD = int(1e9) + 7;

string T;
int n;
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int c[MAX];
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
// remember to put the ‘$’
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

bool is_less(string &s, int p) {
    p = SA[p];
    for(int i = 0; i < s.size(); i++) {
        if(p+i >= n) return false;
        if(s[i] < T[p+i]) return true;
        if(s[i] > T[p+i]) return false;

    }
    return false;

}

bool is_eq(string &s, int p) {
    p = SA[p];
    for(int i = 0; i < s.size(); i++) {
        if(p+i >= n) return false;
        if(s[i] != T[p+i]) return false;
    }
    return true;

}

int main( ) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     #ifdef FSOCIETY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #endif // FSOCIETY

    int t; cin >> t;
    while(t--) {
        cin >> T;
        T.push_back('$');
        n = T.size();
        buildSA();

        int q; cin >> q;
        while(q--) {
            string u; cin >> u;
            int low = 0, high = n-1;
            while(low <= high) {
                int mid = (low+high)/2;
                if(is_less(u, mid)) high = mid-1;
                else low = mid+1;
            }
            if(is_eq(u, high)) cout << "y\n";
            else cout << "n\n";
        }

    }


}
