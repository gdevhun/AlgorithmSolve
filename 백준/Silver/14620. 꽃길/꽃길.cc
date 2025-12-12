#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
int n;
int visited[11][11];
int gardenCost[11][11];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int ret = 1e9;
using namespace std;
bool canPlant(int y, int x)
{
	if (visited[y][x]) return false;
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return false;
	}
	return true;
}
int getFlowerCost(int y,int x)
{
	visited[y][x] = 1;
	int totalCost = gardenCost[y][x];
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		totalCost += gardenCost[ny][nx];
	}
	return totalCost;
}
void eraseFlower(int y,int x)
{
	visited[y][x] = 0;
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		visited[ny][nx] = 0;
	}
}
void flower(int cnt, int sum)
{
	if (cnt==3)
	{
		ret = min(ret, sum);
		return;
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (canPlant(i,j))
			{
				flower(cnt + 1, sum + getFlowerCost(i, j));
				eraseFlower(i, j);
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cin >> gardenCost[i][j];
		}
	}
	flower(0, 0);
	cout << ret;
	return 0;
}