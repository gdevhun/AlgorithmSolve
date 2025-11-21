#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int map[51][51];
bool visited[51][51];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int N, L, R;
int cnt, sum;
vector<pair<int, int>> vec;
void dfs(int y,int x, vector<pair<int,int>> &vec)
{
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
		if (abs(map[ny][nx]-map[y][x])>=L && abs(map[ny][nx]-map[y][x])<=R)
		{
			visited[ny][nx] = true;
			vec.push_back({ ny,nx });
			sum += map[ny][nx];
			dfs(ny, nx, vec);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			cin >> map[i][j];
		}
	}
	while (true)
	{
		bool flag = false;
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<N; j++)
			{
				if (!visited[i][j])
				{
					vec.clear();
					visited[i][j] = true;
					vec.push_back({ i,j });
					sum = map[i][j];
					dfs(i, j, vec);

					if (vec.size() == 1) continue;

					for (pair<int,int> b : vec)
					{
						map[b.first][b.second] = sum / vec.size();
						flag = true;
					}
					
				}
			}
		}
		if (!flag) break;
		cnt++;
	}
	cout << cnt;
	return 0;
}