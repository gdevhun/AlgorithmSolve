#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool visited[101][101];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int main()
{
	int m, n;
	cin >> m >> n;
	int finished = m*n-1;
	int cnt = 0;
	int y = 0, x = 0, dir = 0;
	visited[y][x] = true;

	while (finished--)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny<0||nx<0||ny>=m||nx>=n||visited[ny][nx])
		{	// 이동불가
			dir = (dir + 1) % 4;
			cnt++;
			finished++;
		}
		else //이동가능
		{
			visited[ny][nx] = true;
			y = ny;
			x = nx;
		}
	}
	cout << cnt;
}
	