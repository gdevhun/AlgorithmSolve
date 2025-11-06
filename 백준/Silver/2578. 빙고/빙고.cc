#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
int board[5][5];
using namespace std;
int cnt, num;

bool bingo()
{
	int bingoCnt = 0;
	int correct = 0;
	//가로체크
	for (int i = 0; i < 5; i++)
	{
		correct = 0;
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == 0) correct++;
			if (correct == 5) bingoCnt++;
			if (bingoCnt == 3) return true;
		}
	}

	//세로체크
	for (int i = 0; i < 5; i++)
	{
		correct = 0;
		for (int j = 0; j < 5; j++)
		{
			if (board[j][i] == 0) correct++;
			if (correct == 5) bingoCnt++;
			if (bingoCnt == 3) return true;
		}
	}

	//가로대각선체크
	correct = 0;
	for (int i = 0; i < 5; i++)
	{
		if (board[i][i] == 0) correct++;
		if (correct == 5) bingoCnt++;
		if (bingoCnt == 3) return true;
	}

	//세로대각선체크 0 4, 1 3, 2 2, 3 1, 4 0
	correct = 0;
	int temp = 4;
	for (int i = 0; i < 5; i++)
	{
		if (board[i][temp] == 0) correct++;
		if (correct == 5) bingoCnt++;
		if (bingoCnt == 3) return true;
		temp--;
	}
	return false;
}
int main()
{
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5; j++)
		{
			cin >> board[i][j];
		}
	}

	cnt = 1;
	while (true)
	{
		cin >> num;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] == num)
				{
					board[i][j] = 0;
					break;
				}
				
			}
		}

		if (bingo()) break;
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}