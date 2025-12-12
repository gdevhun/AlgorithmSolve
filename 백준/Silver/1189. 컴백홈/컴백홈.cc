#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char map[6][6];
int visited[6][6];
int r, c, k;
int res;
void dfs(int y,int x,int dist)
{
	//집도착
	if (y==0&&x==c-1)
	{	//거리k이면
		if (dist==k)
		{
			res++;
		}
		return;
	}
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
		if (map[ny][nx] == 'T') continue;
		visited[ny][nx]=1;
		dfs(ny, nx, dist + 1);
		visited[ny][nx] = 0;
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> r >> c >> k;
	for (int i=0; i<r; i++)
	{
		string input;
		cin >> input;
		for (int j=0; j<c; j++)
		{
			map[i][j] = input[j];
		}
	}
	visited[r - 1][0] = 1;
	dfs(r - 1, 0, 1);
	cout << res;
	return 0;
}