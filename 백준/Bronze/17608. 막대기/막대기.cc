#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>vec(n);
	for (int i=0; i<n; i++)
	{
		cin >> vec[i];
	}

	int maxheight = vec[n - 1];
	int cnt = 1;

	for (int i=n-1; i>=0; i--)
	{
		if (vec[i] > maxheight) // 새로 확인한 것이 보이는것보다 크면
		{
			maxheight = vec[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}