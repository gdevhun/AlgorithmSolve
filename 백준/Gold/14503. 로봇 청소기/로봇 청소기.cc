#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <set>
using namespace std;
int map[51][51];
int visited[51][51];
int n, m, d;
int r, c;
int cnt;
int dy[4] = {-1,0,1,0}; //북동남서 0123
int dx[4] = {0,1,0,-1};
//d -> 0북,1동,2남,3서
// 반시계 북->서->남->동
bool isCleanableArea(int y,int x)
{
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		if (map[ny][nx] == 1) continue;
		return true;
	}
	return false;
}
void turnCleaner()
{
	d = (d + 3) % 4;
}
void clean()
{
	while (true)
	{
		if (!visited[r][c])
		{
			visited[r][c] = 1;
			cnt++;
		}

		if (isCleanableArea(r,c)) //주위 4칸 청소가능?
		{
			
			while (true)
			{
				turnCleaner();
				int ny = r + dy[d];
				int nx = c + dx[d];
				if (map[ny][nx]==0&&!visited[ny][nx])
				{
					r = ny;
					c = nx;
					break;
				}
			}
		}
		else //주위 4칸 청소불가능?
		{
			int backDir = (d + 2) % 4;
			int ny = r + dy[backDir];
			int nx = c + dx[backDir];
			if (map[ny][nx]==0)
			{
				r = ny;
				c = nx;
			}
			else
			{
				break;
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// 0 청소x 1 벽
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin >> map[i][j];
		}
	}
	clean();
	cout << cnt;
	return 0;
}
