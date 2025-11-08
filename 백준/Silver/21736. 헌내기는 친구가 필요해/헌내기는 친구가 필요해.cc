#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;
char map[601][601];
int visited[601][601];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int n, m, cnt;
int startY, startX;
void bfs(int y,int x)
{
	queue<pair<int, int>> que;
	que.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty())
	{
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (visited[ny][nx] || ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 'X') continue;
			visited[ny][nx] = visited[ny][nx] + 1;
			if (map[ny][nx] == 'P') cnt++;
			que.push({ ny,nx });
		}
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		string input;
		cin >> input;
		for (int j=0; j<m; j++)
		{
			map[i][j] = input[j];
			if (map[i][j]=='I')
			{
				startY = i; startX = j;
			}
		}		
	}
	bfs(startY, startX);

	if (cnt == 0) cout << "TT";
	else cout << cnt;
	
    return 0;
}