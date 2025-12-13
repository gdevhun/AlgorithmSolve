#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int n;
int temp;
int paper[1001][1001];
map<int, int>mymap;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;

	for (int i=0; i<n; i++)
	{
		temp++;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int y=a; y<a+c; y++)
		{
			for (int x=b; x<b+d; x++)
			{
				paper[y][x] = temp;
			}
		}
	}
	/*for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			cout << paper[i][j];
		}
		cout << endl;
	}*/
	for (int i=0; i<1001; i++)
	{
		for (int j=0; j<1001; j++)
		{
			if (paper[i][j] == 0) continue;
			mymap[paper[i][j]]++;
		}
	}

	for (int i=1; i<=n; i++)
	{
		cout << mymap[i] << "\n";
	}
	return 0;
}