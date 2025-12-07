#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int r, c;
char map[21][21];
bool visited[26];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int maxnum = 0;
void dfs(int y,int x,int cnt)
{
	maxnum = max(maxnum, cnt);
	for (int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		int alpha = map[ny][nx] - 'A';
		if (visited[alpha]) continue;

		visited[alpha] = true;
		dfs(ny, nx, cnt + 1);
		visited[alpha] = false; //백트래킹 : 방문해제
	}
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < c; j++) {
			map[i][j] = input[j];
		}
	}
	visited[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << maxnum;

	return 0;
}