/* USER: 308958 (osdajigu) */
/* PROBLEM: 2957 (11857 - Driving Range) */
/* SUBMISSION: 15116928 */
/* SUBMISSION TIME: 2015-03-10 16:02:09 */
/* LANGUAGE: 3 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define PB push_back
#define MAX 1000000
using namespace std;

struct Edge {
	int from, to, cost;

	bool operator < (const Edge & e) const {
		return cost < e.cost;
	}
};

int N, M, father[MAX], range[MAX];
vector<Edge> edges;

void init() {
	edges.clear();
	for(int i = 0; i <= N; i++) {
		father[i] = i;
		range[i] = 0;
	}
}

int find(int x) {
	if(x == father[x]) return x;
	return father[x] = find(father[x]);
}

void merge(int a, int b) {
	int A = find(a);
	int B = find(b);
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
			ans = e.cost;
		}
	}
	if(nodes == N - 1) {
		cout << ans << "\n";
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}

int main() {
	while(cin >> N >> M && (M != 0 || N != 0)) {
		init();
		Edge e;
		for(int i = 0; i < M; i++) {
			cin >> e.from >> e.to >> e.cost;
			edges.PB(e);
		}
		kruskal();
	}
	return 0;
}
