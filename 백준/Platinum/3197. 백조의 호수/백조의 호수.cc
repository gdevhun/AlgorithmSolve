#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int r, c;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char map[1501][1501];
int visited[1501][1501];
queue<pair<int, int>> swanque;
queue<pair<int, int>> nextdayswanque;
queue<pair<int, int>> waterque;
queue<pair<int, int>> nextdaywaterque;
bool isAvailableSwanMet() {
	while (!swanque.empty()) {
		int cy = swanque.front().first;
		int cx = swanque.front().second;
		swanque.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;

			//물이면 계속 탐색
			if (map[ny][nx] == '.') {
				swanque.push({ ny,nx });
			}
			//다른 백조 발견
			else if (map[ny][nx] == 'L') {
				return true;
			}
			//얼음이면 다음 날을 위해 nextque에 저장
			else if (map[ny][nx] == 'X') {
				nextdayswanque.push({ ny,nx });
			}
		}
	}
	return false;
}
void meltIcePerOneDay() {
	while (!waterque.empty()) {
		int cy = waterque.front().first;
		int cx = waterque.front().second;
		waterque.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx] == 'X') {
				map[ny][nx] = '.';
				nextdaywaterque.push({ ny,nx });
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	//'.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간
	bool firstSwan = true;
	cin >> r >> c;
	for (int i=0; i<r; i++)
	{
		string input;
		cin >> input;
		for (int j=0; j<c; j++)
		{
			map[i][j] = input[j];
			//백조의 위치도 물임. -> 물이나 백조면 워터큐에 삽입
			if (map[i][j] == '.' || map[i][j] == 'L') {
				waterque.push({ i,j });
			}
			//첫번째 백조만 위치 찾아서 넣기
			if (map[i][j] == 'L' && firstSwan) {
				swanque.push({ i,j });
				visited[i][j] = 1;
				firstSwan = false;
			}
		}
	}

	int daycnt = 0;
	while (true) {
		if (isAvailableSwanMet()) {
			break;
		}
		//하루 얼음 녹이기
		meltIcePerOneDay();

		//다음날을 위한 큐들 초기화
		waterque = nextdaywaterque;
		nextdaywaterque = queue<pair<int, int>>();

		swanque = nextdayswanque;
		nextdayswanque = queue<pair<int, int>>();

		daycnt++;
	}

	cout << daycnt << "\n";
	return 0;
}
