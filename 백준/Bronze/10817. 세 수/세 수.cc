#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<int> vec;
	vec.resize(3);
	for (int i=0; i<3; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	cout << vec[1];
	return 0;
}