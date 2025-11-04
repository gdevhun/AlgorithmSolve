#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	int star_idx = pattern.find("*");
	string prefix = pattern.substr(0, star_idx);
	string suffix = pattern.substr(star_idx + 1);
	while (n--)
	{
		string input;
		cin >> input;
		if (input.size() < prefix.size() + suffix.size()) cout << "NE" << "\n";
		else
		{
			if (prefix == input.substr(0, prefix.size()) && suffix == input.substr(input.size() - suffix.size()))
			{
				cout << "DA" << "\n";
			}
			else cout << "NE" << "\n";
		}
	}
	
	return 0;
}