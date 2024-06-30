#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>>vec;
int main() {
	int n; //점의 개수
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
}