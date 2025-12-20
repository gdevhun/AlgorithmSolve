#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <set>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input, bomb;
	cin >> input >> bomb;
	int bombLen = bomb.size();
	stack<char>st;
	for (int i=0; i<input.size(); i++)
	{
		st.push(input[i]);
		if (st.size()>=bombLen)
		{
			string temp = "";
			for (int j=0; j<bombLen; j++)
			{
				temp += st.top();
				st.pop();
			}
			reverse(temp.begin(),temp.end());
			if (temp!=bomb)
			{
				for (auto elem: temp)
				{
					st.push(elem);
				}
			}
		}
	}
	if (st.empty())
	{
		cout << "FRULA";
	}
	else
	{
		string res = "";
		while (!st.empty())
		{
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());
		cout << res;
	}


	return 0;
}