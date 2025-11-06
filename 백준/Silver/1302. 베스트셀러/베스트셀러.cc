#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int n;
string maxbook;
map<string, int>book;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i=0; i<n; i++)
	{
		string str;
		cin >> str;
		book[str]++;
	}
	int maxcnt = 0; string answer = "";
	for (auto it=book.begin(); it!=book.end(); ++it)
	{
		if (maxcnt<it->second)
		{
			maxcnt = it->second;
			answer = it->first;
		}
	}
	cout << answer;
	return 0;

}