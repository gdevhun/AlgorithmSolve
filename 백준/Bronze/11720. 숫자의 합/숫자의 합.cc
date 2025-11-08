#include<iostream>
#include<queue>
#include<algorithm>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	//A = 65 a=97
	int n;
	int sum = 0;
	cin >> n;
	string input;
	cin >> input;
	for (int i=0; i<n; i++)
	{
		sum += input[i] - '0';
	}
	cout << sum;
    return 0;
}