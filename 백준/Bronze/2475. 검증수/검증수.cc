
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int arr[5];
	for (int i=0; i<5; i++)
	{
		cin>>arr[i];
	}
	int res = 0;
	for (int i=0; i<5; i++)
	{
		res += arr[i] * arr[i];
	}
	int ret = res % 10;
	cout << ret;
	return 0;
}
	