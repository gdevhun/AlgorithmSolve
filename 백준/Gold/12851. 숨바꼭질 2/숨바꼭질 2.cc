#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
int dist[100001];
int cnt[100001];
queue<int>que;
void bfs(int start)
{
	dist[start] = 1;
	cnt[start] = 1;
	que.push(start);

	while (!que.empty())
	{
		int cx = que.front();
		que.pop();

		int next[3] = { cx - 1, cx + 1, cx * 2 };

		for (int i=0; i<3; i++)
		{
			int nx = next[i];
			if (nx < 0 || nx >= 100001) continue;

			if (!dist[nx])
			{
				que.push(nx);
				dist[nx] = dist[cx] + 1;
				cnt[nx] += cnt[cx];
			}
			else if (dist[nx]==dist[cx]+1)
			{
				cnt[nx] += cnt[cx];
			}
		}
		
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if (n == k) { cout << 0 << "\n" << 1;  return 0; }
	bfs(n);
	cout << dist[k]-1 << "\n" << cnt[k];
	
	return 0;
}