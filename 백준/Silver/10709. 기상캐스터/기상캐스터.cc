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

	for (int i = 0; i < h; i++) {
		int time = -1;
		for (int j = 0; j < w; j++) {
			if (sky[i][j] == 0) time = 0;
			else if (time != -1) {
				sky[i][j] = ++time;
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
