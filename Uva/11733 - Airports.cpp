/* USER: 308958 (osdajigu) */
/* PROBLEM: 2833 (11733 - Airports) */
/* SUBMISSION: 14621113 */
/* SUBMISSION TIME: 2014-12-02 20:32:55 */
/* LANGUAGE: 3 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define MAX 10000 + 5
using namespace std;

struct Edge {
	int from, to, cost;
	
	bool operator<(const Edge &e) const {
		return cost < e.cost;
	}
};

int nTest, N, M, A, costMin;
vector<Edge> edges;
int fathers[MAX], height[MAX];



void initializate() {
	for(int i = 1; i <= N; i++) {
		fathers[i] = i;
		height[i] = 0;
	}
	costMin = 0;
}

int find(int node) {
	if(fathers[node] == node) return node;
	return fathers[node] = find(fathers[node]);
}

void unionByHeight(int x, int y) {
	int fatherX = find(x);
	int fatherY = find(y);
	if(height[fatherX] > height[fatherY])
		fathers[fatherX] = fatherY;
	else {
		fathers[fatherY] = fatherX;
		if(height[fatherX] == height[fatherY])
			height[fatherY]++;
	}
}

void kruskal() {
	initializate();
	sort(edges.begin(), edges.end());
	int k = edges.size();
	for(int i = 0; i < k; i++) {
		if(find(edges[i].from) != find(edges[i].to) && edges[i].cost < A ) {
			unionByHeight(edges[i].from, edges[i].to);
			costMin += edges[i].cost;
		}
	}
}

int countAirports() {
	int ans = 0;
	for(int i = 1; i <= N; i++)
		if(fathers[i] == i) ans++;
	return ans;
}



int main() {
	int cases = 1;
	cin >> nTest;
	while(nTest--) {
		//cin >> N >> M >> A;
		scanf("%d %d %d", &N, &M, &A);
		edges.clear();
		for(int i = 0; i < M; i++) {
			Edge e;
			cin >> e.from >> e.to >> e.cost;		
			edges.push_back(e);
		}
		kruskal();
		int auxAir = countAirports();
		//cout << "Case #" << cases++ << ": " << costMin + (auxAir * A) << " " << auxAir << endl; 
		printf("Case #%d: %d %d\n", cases++, costMin + (auxAir * A), auxAir);
	}
	return 0;
}