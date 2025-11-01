#include<iostream>
#include <string>
using namespace std;


int main()
{
	int num[10] = {0,};
	long long a, b, c;
	cin >> a >> b >> c;
	long long answer = a * b * c;
	string str = to_string(answer);
	for (char c : str)
	{
		int digit = c - '0';
		num[digit]++;
	}
	for (int i=0; i<=9; i++)
	{
		cout << num[i] << "\n";
	}
	return 0;
}