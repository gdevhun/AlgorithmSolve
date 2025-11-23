#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int scvhp[3];
int dist[61][61][61]; 
int damage[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};
struct A
{
	int a, b, c;
};
queue<A> que;
int bfs(int a,int b,int c)
{
	dist[a][b][c] = 1;
	que.push({ a,b,c });
	while (!que.empty())
	{
		int ca = que.front().a;
		int cb = que.front().b;
		int cc = que.front().c;
		que.pop();
		if (dist[0][0][0]) break;

		for (int i=0; i<6; i++)
		{
			int na = max(0, ca - damage[i][0]);
			int nb = max(0, cb - damage[i][1]);
			int nc = max(0, cc - damage[i][2]);
			if (dist[na][nb][nc]) continue;
			dist[na][nb][nc] = dist[ca][cb][cc] + 1;
			que.push({ na,nb,nc });
		}
	}
	return dist[0][0][0] - 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> scvhp[i];
	cout << bfs(scvhp[0], scvhp[1], scvhp[2]);

	return 0;
}