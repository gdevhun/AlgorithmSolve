#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;
bool visited[101][101];
char map[101][101];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int n;

void dfs1(int y,int x) //일반사람
{
	visited[y][x] = true;
	char selectedColor = map[y][x];

	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		if (map[ny][nx] != selectedColor) continue;
		dfs1(ny, nx);
	}
}
void dfs2(int y, int x) //적록색약
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		if (map[ny][nx] == 'B') continue;
		dfs2(ny, nx);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int original = 0;
	int unique = 0;

	cin >> n;
	for (int i=0; i<n; i++)
	{
		string input;
		cin >> input;
		for (int j=0; j<n; j++)
		{
			map[i][j] = input[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (!visited[i][j])
			{
				dfs1(i, j);
				original++;
			}
		}
	}

	fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (!visited[i][j])
			{
				if (map[i][j] == 'R' || map[i][j] == 'G')
				{
					dfs2(i, j); unique++;
				}
				else
				{
					dfs1(i, j); unique++;
				}
			}
		}
	}
	
	cout << original << " " << unique;
    return 0;
}