#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi vis;
vector<vector<int>> graph;

int dfs(int cur_node, int par_node, int& nodes_cnt) {
	if (vis[cur_node])
		return 1;

	vis[cur_node] = 1;

	for (auto child_node: graph[cur_node]) if(child_node!=par_node)
	{
		++nodes_cnt;

		if (dfs(child_node, cur_node, nodes_cnt) == 1)
			return 1;
	}
	return 0;
}

int main() {
	int n,m;
	cin >> n>>m;
	graph= vector<vector<int>>(n);
	vis = vi(n);
	
	for (int i = 0; i < m; i++)
	{
		int e1, e2;
		cin >> e1 >> e2;
		--e1, --e2;
		graph[e1].push_back(e2);
		graph[e2].push_back(e1);
	}

	int remove = 0;
	for (int i = 0; i < n; i++)if (!vis[i])
	{
		int cnt = 0;
		int sol = dfs(i, -1, cnt);

		if (sol == 1)
			remove += (cnt % 2 == 1);
	}
	if ((n - remove) % 2 == 1)
		remove++;

	cout << remove;
}