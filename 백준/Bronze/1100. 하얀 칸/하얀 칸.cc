#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;
char map[8][8];
char mapblank[8][8];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int cnt = 0;
	bool flag = false;
	for (int i=0; i<8; i++)
	{
		
		for (int j=0; j<8; j++)
		{
			if (flag == false)
			{
				mapblank[i][j] = 'W';
			}
			else mapblank[i][j] = 'B';
			flag = !flag;
			if (j == 7) flag = !flag;
		}
	}
	for (int i=0 ;i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			cin >> map[i][j];

		}
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (mapblank[i][j]=='W' && map[i][j]=='F')
			{
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}
	