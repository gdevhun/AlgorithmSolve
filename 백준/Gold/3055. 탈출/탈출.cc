#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <set>
char map[51][51];
int dist[51][51];
int waterdist[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int r, c;
int startY, startX;
int endY, endX;
using namespace std;

queue<pair<int, int>> distque;
queue<pair<int, int>> waterque;

void bfs(int y,int x)
{
	dist[y][x] = 1;
	distque.push({ y,x });
	while (!distque.empty())
	{
		int cy = distque.front().first;
		int cx = distque.front().second;
		distque.pop();

		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || dist[ny][nx]) continue;
			if (map[ny][nx] == 'X') continue;
			// 물이 0이아니거나(물이차있거나) 고슴도치가 현재위치에 1을 더했을때 같거나 크면(물이 찰 예정이면) 못감
			if (waterdist[ny][nx]!=0 && dist[cy][cx] + 1 >= waterdist[ny][nx]) continue;
			dist[ny][nx] = dist[cy][cx] + 1;
			distque.push({ ny,nx });
		}
	}
}
void waterbfs()
{
	while (!waterque.empty())
	{
		int cy = waterque.front().first;
		int cx = waterque.front().second;
		waterque.pop();

		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || waterdist[ny][nx]) continue;
			if (map[ny][nx] == 'X') continue;
			if (map[ny][nx] == 'D') continue;
			waterdist[ny][nx] = waterdist[cy][cx] + 1;
			waterque.push({ ny,nx });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// 빈곳 . / 물 * /돌 x /비버굴 D /고슴도치 S

	cin >> r >> c;
	for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
		{
			cin >> map[i][j];
			if (map[i][j]=='*')
			{
				waterdist[i][j] = 1;
				waterque.push({ i,j });
			}
			else if (map[i][j]=='S')
			{
				startY = i; startX = j;
			}
			else if (map[i][j] == 'D')
			{
				endY = i; endX = j;
			}
		}
	}
	waterbfs();
	bfs(startY, startX);
	if (dist[endY][endX]==0)
	{
		cout << "KAKTUS" << "\n";
	}
	else
	{
		cout << dist[endY][endX] - 1 << "\n";
	}
	/*for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
		{
			cout << dist[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << waterdist[i][j];
		}
		cout << endl;
	}*/
	return 0;
}