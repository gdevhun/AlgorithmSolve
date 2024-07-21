#include<iostream>
#include<vector>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp;
	int a[101][101];
	int b[101][101];
	int c[101][101] = { 0 };  // 결과 행렬 초기화

	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp; 
			a[i][j] = temp;
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> temp;
			b[i][j] = temp;
		}
	}
	
	// 행렬 곱셈 계산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}

	// 결과 행렬 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
}
