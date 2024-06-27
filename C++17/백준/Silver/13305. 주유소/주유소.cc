#include<iostream>
using namespace std;
int main() {
	int citycost[100005];
	int dist[100005];
	int n; //도시의 갯수
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> citycost[i];
	}
	long long mincost = 0; //최소가격
	int cost = citycost[0]; //초기 시작점 가격
	for (int i = 0; i < n-1; i++) {
		if (cost > citycost[i]) {
			cost = citycost[i];
		}
		mincost += (long long)cost * dist[i];
	}
	cout << mincost;
	return 0;
}