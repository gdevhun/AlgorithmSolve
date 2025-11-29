#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> vec;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int elem;
		cin >> elem;
		vec.push_back(elem);
	}
	sort(vec.begin(), vec.end());
	
	cout<< vec[0] * vec[n-1];

	return 0;
}