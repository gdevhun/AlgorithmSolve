#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main()
{
	int x, y;
	cin >> x >> y;
	int daycnt = 0;
	for (int i = 1; i < x; i++) {
		daycnt += month[i];
	}
	daycnt += y;

	int idx = (daycnt - 1) % 7;
	cout << week[idx];
	return 0;
}
	