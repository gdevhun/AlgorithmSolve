#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dist[10000001];
int prevnode[10000001];
void bfs(int start) {
	queue<int> que;
	que.push(start);
	dist[start] = 1;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		
		int dx[3] = { cur - 1, cur / 2, cur / 3 };

		for (int i=0; i<3; i++)
		{
			int nx = dx[i];
			if (i == 1 && cur % 2 != 0) continue;
			if (i == 2 && cur % 3 != 0) continue;
			if (nx < 1 || dist[nx]) continue;
			dist[nx] = dist[cur] + 1;
			prevnode[nx] = cur;
			que.push(nx);

		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	bfs(n);

	cout << dist[1]-1 << "\n";
	vector<int> path;
	int cur = 1;
	while (true)
	{
		path.push_back(cur);
		if (cur == n) break;
		cur = prevnode[cur];
	}
	//path.push_back(1);
	reverse(path.begin(), path.end());
	for (auto elem : path)
	{
		cout << elem << " ";
	}
	return 0;
}
	