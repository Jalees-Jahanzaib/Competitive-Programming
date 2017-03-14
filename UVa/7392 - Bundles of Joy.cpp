#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;

bool cmp (const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) {
	return a.first.size() > b.first.size();
}

bool belong (const vector<int> &a, const vector<int> &b) {
	for (int i = 0; i < a.size(); ++i)
		if (a[i] == b[0]) return true;
	return false;
}

int go (int u, graph &g, vector<int> &value, vector<pair<vector<int>, int>> &p) {
	int ans = value[p[u].second];
	int sum = 0;
	int children = 0;
	for (auto &v : g[u]) {
		sum += go(v, g, value, p);
		children += p[v].first.size();
	}
	if (children == p[u].first.size()) ans = min(ans, sum);
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m;
		vector<pair<vector<int>, int>> packages(m + 1);
		vector<int> value(m + 1);
		for (int i = 1; i <= m; ++i) {
			cin >> value[i] >> k;
			vector<int> &cur = packages[i].first;
			cur = vector<int>(k);
			for (auto &x : cur)
				cin >> x;
			packages[i].second = i;
		}

		vector<int> &cur = packages[0].first;
		packages[0].second = 0;
		cur = vector<int>(n);
		for (int i = 0; i < n; ++i) cur[i] = i + 1;
		value[0] = INT_MAX;

		sort(packages.begin(), packages.end(), cmp);

		graph g(m + 1);
		for (int i = 0; i <= m; ++i)
			for (int j = i - 1; j >= 0; --j)
				if (belong(packages[j].first, packages[i].first)) {
					g[j].push_back(i);
					break;
				}

		cout << go(0, g, value, packages) << '\n';
	}
}
