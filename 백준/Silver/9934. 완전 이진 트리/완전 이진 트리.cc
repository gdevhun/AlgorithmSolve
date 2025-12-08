#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
vector<int> building;
vector<vector<int>> tree;
int k, n;
void solve(int start, int end, int level)
{
	if (start > end) return;

	int mid = (start + end) / 2;

	tree[level].push_back(building[mid]);

	solve(start, mid - 1, level + 1);
	solve(mid + 1, end, level + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> k; //깊이
	n = pow(2, k) - 1; //노드 개수

	tree.resize(k);
	building.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> building[i];
	}
	solve(0, n - 1, 0);
	for (int i=0; i<k; i++)
	{
		for (auto elem : tree[i])
		{
			cout << elem << " ";
		}
		cout << "\n";
	}
	return 0;

}