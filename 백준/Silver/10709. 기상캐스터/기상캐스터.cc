#include <iostream>
using namespace std;
string input;
int h, w;
int sky[101][101];
int main() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> input;
		for (int j = 0; j < w; j++) {
			if (input[j] == '.') sky[i][j] = -1;
			else if (input[j] == 'c') sky[i][j] = 0;
		}
	}

	// 구름이 오른쪽으로 몇 분 후에 도달할지 계산
	for (int i = 0; i < h; i++) {
		int time = -1;
		for (int j = 0; j < w; j++) {
			if (sky[i][j] == 0) {
				time = 0;  // 구름이 있는 구역을 발견하면 시간 0
			}
			else if (time != -1) {
				time++;  // 구름이 있는 구역 이후로 1분씩 증가
				sky[i][j] = time;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << sky[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
