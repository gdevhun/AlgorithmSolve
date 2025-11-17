#include<iostream>
#include<vector>
using namespace std;
bool infected[101];
vector<int> cpt[101];
void dfs(int x) {
	infected[x] = true;
	for (int i = 0; i < cpt[x].size(); i++) {
		if (infected[cpt[x][i]]) continue;
		dfs(cpt[x][i]);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cpt[a].push_back(b);
		cpt[b].push_back(a);
	}
	dfs(1);
	int total = 0;
	for (int j = 1; j <= n; j++) {
		if (infected[j+1]) total++;
	}
	cout << total << endl;
	return 0;
}