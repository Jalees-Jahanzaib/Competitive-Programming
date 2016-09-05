#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, int>
#define MAX 400100
#define INF INT_MIN / 5;
#define ll long long

using namespace std;

string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N], LCP[MAX_N];
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

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =
			(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;
	}
}

void buildLCP(){
    int L = 0;
    LCP[0] = 0;
    for(int i = 0; i < n; i++) {
           if(i == SA[0]) continue;
           while(T[i + L] == T[SA[ RA[i]-1] + L]) L++;
           LCP[ RA[i] ] = L;
           L = max(L-1, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);/**/
    //freopen("input.txt", "r", stdin)

    int t; cin >> t;
    while(t--) {

    }

}
