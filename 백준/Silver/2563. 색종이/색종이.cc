#include<iostream>
#include <string>
#include <vector>
int canvas[101][101];
using namespace std;
int main()
{
	int papernum;
	int area = 0;
	cin >> papernum;
	for (int i=0; i<papernum; i++)
	{
		int x, y;
		cin >> x >> y; //x=3 y=7

		for (int i=y; i<y+10; i++)
		{
			for (int j=x; j<x+10; j++)
			{
				canvas[i][j] = 1;
			}
		}
	}

	for (int i=0; i<101; i++)
	{
		for (int j=0; j<101; j++)
		{
			if (canvas[i][j] == 1) area++;
		}
	}
	cout << area;
}
	