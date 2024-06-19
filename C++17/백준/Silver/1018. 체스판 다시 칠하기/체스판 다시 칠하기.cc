#include<iostream>
using namespace std;
char chess[51][51];
char white_arr[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};

char black_arr[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
int start_black(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i+x][j+y] != black_arr[i][j])
				ret++;
		}
	}
	return ret;
}
int start_white(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i+x][j+y] != white_arr[i][j])
				ret++;
		}
	}
	return ret;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}
	int res = 64; //다칠하는경우 8x8=64
	int whitenum; int blacknum;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			whitenum = start_white(i, j);
			blacknum = start_black(i, j);
			if (whitenum < blacknum) { 
				if (whitenum < res) res = whitenum;
			}
			else {
				if (blacknum < res) res = blacknum;
			}
		}
	}
	cout << res << '\n';
}