#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int w, h, testnum;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char map[1001][1001];
int firedist[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> que;
queue<pair<int, int>> fireque;
void bfs()
{
	while (!que.empty())
	{
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		for (int i=0; i<4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w || dist[ny][nx]) continue;
			if (map[ny][nx] == '#') continue;
			if (firedist[ny][nx] != 0 && firedist[ny][nx] <= dist[cy][cx] + 1) continue;
			dist[ny][nx] = dist[cy][cx] + 1;
			que.push({ ny,nx });
		}
	}
}
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
			if (ny < 0 || nx < 0 || ny >= h || nx >= w || firedist[ny][nx]) continue;
			if (map[ny][nx] == '#') continue;
			firedist[ny][nx] = firedist[cy][cx] + 1;
			fireque.push({ ny,nx });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//  '.' : 빈 공간
	//  '#' : 벽
	//	'@' : 상근이의 시작 위치
	//	'*' : 불
	cin >> testnum;
	while (testnum--)
	{
		cin >> w >> h;
		fill(&firedist[0][0], &firedist[0][0] + 1001 * 1001, 0);
		fill(&dist[0][0], &dist[0][0] + 1001 * 1001, 0);
		int ret = 1e9;
		for (int i=0; i<h; i++)
		{
			string input;
			cin >> input;
			for (int j=0; j<w; j++)
			{
				map[i][j] = input[j];
				if (map[i][j]=='*')
				{
					fireque.push({ i,j });
					firedist[i][j] = 1;
				}
				else if (map[i][j]=='@')
				{
					que.push({ i,j });
					dist[i][j] = 1;
				}
			}
		}
		firebfs();
		bfs();
		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
			{
				if (i==0||j==0||i==h-1||j==w-1)
				{
					if (dist[i][j]>0)
					{
						ret = min(ret, dist[i][j]);
					}
				}
			}
		}
		if (ret == 1e9) cout << "IMPOSSIBLE" << "\n";
		else cout << ret << "\n";
	}
	/*for (auto elem : exit)
		{
			cout << elem.first<< " " <<elem.second << "\n";
		}

		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
			{
				cout << dist[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cout << firedist[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
	return 0;
}