#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int mymap[101][101];
void placeArea(int x1, int y1, int x2, int y2)
{
	for (int y=y1; y<y2; y++) //2  4
	{
		for (int x=x1; x<x2; x++) //1  4
		{
			mymap[y][x] = 1;
		}
	}
}
int main()
{
	//첫 번째와 두 번째의 정수는 사각형의 왼쪽 아래 꼭짓점의 x좌표, y좌표이고
	//세 번째와 네 번째의 정수는 사각형의 오른쪽 위 꼭짓점의 x좌표, y좌표이다.
	for (int i=0; i<4; i++)
	{
		int x1, x2, y1, y2; //1244
		cin >> x1 >> y1 >> x2 >> y2;
		placeArea(x1, y1, x2, y2);
	}
	int cnt = 0;
	for (int i=0; i<101; i++)
	{
		for (int j=0; j<101; j++)
		{
			if (mymap[i][j] == 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}