#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool visited_dfs[1001];
bool visited_bfs[1001];
vector<int>vec[1001];
queue<int>que;
void dfs(int cur) {
	cout << cur << " ";
	visited_dfs[cur] = true;
	for (int i = 0; i < vec[cur].size(); i++) {
		int next = vec[cur][i];
		if (visited_dfs[next]) continue;
		dfs(next);
	}
}
void bfs(int root) {
	que.push(root);
	visited_bfs[root] = true;
	while (!que.empty()) {
		int cur = que.front();
		cout << cur << " ";
		que.pop();
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];
			if (visited_bfs[next]) continue;
			que.push(next);
			visited_bfs[next] = true;
		}
	}
}
int main() {
	int n, m, v;
	cin >> n >> m >> v; //정점 수, 간선 수, 정점 번호v
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);
	cout << '\n';
	bfs(v);
}
