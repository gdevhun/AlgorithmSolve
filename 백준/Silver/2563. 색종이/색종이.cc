#include<iostream>
using namespace std;
int arr[105][105] = { 0, };
int main() {
	int total;
	cin >> total;
	for (int i = 0; i < total; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[a + j][b + k] = 1;
			}
		}
	}
	int area = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == 1) area++;
		}
	}
	cout << area << endl;
}