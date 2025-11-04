
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//1분 1대당 A원, 1분 2대당 B원, 1분 3대당 C원
	vector<int> vec(101);
	int A, B, C;
	cin >> A >> B >> C;

	for (int i=0; i<3; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j=a; j<b; j++)
		{
			vec[j]++;
		}
	}
	int res = 0;
	for (int i=0; i<101; i++)
	{
		if (vec[i] == 1) res += vec[i] * A;
		else if (vec[i] == 2) res += vec[i] * B;
		else if (vec[i] == 3) res += vec[i] * C;
	}
	cout << res;
	return 0;
}