#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;
int n, m;
vector<int>graph[1001];
bool visited[1001];
void dfs(int cur)
{
	visited[cur] = true;
	for (int i=0; i<graph[cur].size(); i++)
	{
		if (visited[graph[cur][i]]) continue;
		dfs(graph[cur][i]);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;

	for (int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	for (int i=1; i<=n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
    return 0;
}