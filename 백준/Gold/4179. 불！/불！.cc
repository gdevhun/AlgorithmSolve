#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int r, c;
int ret = 1e9;
char map[1001][1001];
int distPerson[1001][1001];
int distFire[1001][1001];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<int, int>> fireque;
queue<pair<int, int>> personque;
void firebfs()
{
	while (!fireque.empty())
	{
		int cy = fireque.front().first;
		int cx = fireque.front().second;
		fireque.pop();
		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || distFire[ny][nx]) continue;
			if (map[ny][nx] == '#') continue;
			distFire[ny][nx] = distFire[cy][cx] + 1;
			fireque.push({ ny,nx });
		}
	}
}
void personbfs()
{
	while (!personque.empty())
	{
		int cy = personque.front().first;
		int cx = personque.front().second;
		personque.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || distPerson[ny][nx]) continue;
			if (map[ny][nx] == '#') continue;
			// 불이 없거나, 지훈이가 먼저 도착할 수 있으면
			if (distFire[ny][nx] != 0 && distFire[ny][nx] <= distPerson[cy][cx] + 1) continue;
			distPerson[ny][nx] = distPerson[cy][cx] + 1;
			personque.push({ ny,nx });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
		{
			cin >> map[i][j];
			if (map[i][j]=='F')
			{
				fireque.push({ i,j });
				distFire[i][j] = 1;
			}
			else if (map[i][j]=='J')
			{
				personque.push({ i,j });
				distPerson[i][j] = 1;
			}
		}
	}
	firebfs();
	personbfs();
	
	for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
		{
			if (i==0||i==r-1||j==0||j==c-1)
			{
				// 가장자리, 지훈이가 도달 가능하면
				if (distPerson[i][j]>0)
				{
					ret = min(ret, distPerson[i][j]);
				}
			}
		}
	}
	if (ret == 1e9) cout << "IMPOSSIBLE";
	else cout << ret;
}