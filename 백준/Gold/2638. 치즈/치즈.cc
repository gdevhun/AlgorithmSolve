#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <set>
using namespace std;
int n, m;
int map[101][101];
int visited[101][101];  // 외부 공기 표시
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

//외부 공기 모두 visited에 1로 기록하는 함수
void checkOuterAir(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		if (map[ny][nx] == 1) continue;
		checkOuterAir(ny,nx);
	}
}

//모든 치즈가 녹았는지 확인 함수
bool hasCheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

//하루 치즈녹이기 함수
void meltCheese() {
	queue<pair<int, int>> toMeltQue;

	//녹일 치즈 찾아 큐에 넣기
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] == 1) {
				int outerCnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if (visited[ny][nx]) outerCnt++;
					if (outerCnt >= 2) toMeltQue.push({ y,x });
				}
			}
		}
	}

	//녹이기
	while (!toMeltQue.empty()) {
		int y = toMeltQue.front().first;
		int x = toMeltQue.front().second;
		toMeltQue.pop();
		map[y][x] = 0;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

	int day = 0;

	while (hasCheese()) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		checkOuterAir(0, 0);
		day++;
		meltCheese();
	}

	cout << day;
    return 0;
}