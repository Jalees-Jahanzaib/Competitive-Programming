/* USER: 308958 (osdajigu) */
/* PROBLEM: 2757 (11710 - Expensive subway) */
/* SUBMISSION: 15116786 */
/* SUBMISSION TIME: 2015-03-10 15:35:36 */
/* LANGUAGE: 3 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define PB push_back
using namespace std;

struct Edge {
	string from, to;
	int cost;
	
	bool operator < (const Edge & e) const {
		return cost < e.cost;	
	}
};

int N, M;
map<string, string> father;
vector<Edge> edges;

string find(string x) {
	if(x == father[x]) return x;
	return father[x] = find(father[x]);
}

void merge(string a, string b) {
	string A = find(a);
	string B = find(b);
	father[A] = B;
}

void kruskal() {
	sort(edges.begin(), edges.end());
	Edge e;
	int nodes = 0, ans = 0;
	for(int i = 0; i < edges.size(); i++) {
		e = edges[i];
		if(find(e.from) != find(e.to)) {
			merge(e.from, e.to);
			nodes++;
			ans += e.cost;
		}
	}
	if(nodes == N - 1) {
		cout << ans << "\n";
	}
	else {
		cout << "Impossible\n";
	}
	
	
}

int main() {
	while(cin >> N >> M) {
		if(N == 0 && M == 0) break;
		edges.clear();
		string city;
		for(int i = 0; i < N; i++) {
			cin >> city;
			father[city] = city;
		}
		Edge e;
		for(int i = 0; i < M; i++) {
			cin >> e.from >> e.to >> e.cost;
			edges.PB(e);
		}
		cin >> city;
		kruskal();
	}
	return 0;
}
