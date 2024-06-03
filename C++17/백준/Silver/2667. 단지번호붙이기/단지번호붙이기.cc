#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int map[26][26];
bool visited[26][26];
vector<int>vec;

int n; //지도의 크기
int total; //총 단지수(그래프개수)
int num; //단지내 집 수(그래프요소)

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool in_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}
void dfs(int x,int y) {
	visited[x][y] = true;
	num++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visited[nx][ny] && in_range(nx, ny) 
			&& map[nx][ny] == '1') {
			visited[nx][ny] = true;  dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j];
		}
	}
	for (int i = 0; i < n; i++) { //완전탐색
		for (int j = 0; j < n; j++) {
			if (map[i][j] != '1' || visited[i][j]) continue;
			num = 0;
			dfs(i, j);
			vec.push_back(num);
			total++;
		}
	}
	sort(vec.begin(), vec.end());
	cout << total << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	return 0;
}