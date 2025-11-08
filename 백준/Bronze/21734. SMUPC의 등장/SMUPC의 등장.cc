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
	string input;
	cin >> input;

	for (int i=0; i<input.size(); i++)
	{
		string cnt = to_string((int)input[i]);
		int sum = 0;
		for (int j=0; j<cnt.size(); j++)
		{
			sum += cnt[j]-'0';
		}
		for (int k=0; k<sum; k++)
		{
			cout << input[i];
		}
		cout << "\n";
	}
	
    return 0;
}