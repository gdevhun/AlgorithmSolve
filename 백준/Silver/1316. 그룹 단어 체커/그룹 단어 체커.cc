#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int cnt[26];
int n, ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// A 65 a 97
	cin >> n;
	for (int k=0; k<n; k++)
	{
		string input;
		cin >> input;

		fill(cnt, cnt + 26, 0);
		bool isContinuous = true;
		char prev = 0;

		for (int i=0; i<input.size(); i++)
		{
			char cur = input[i];
			if (cur!=prev) //문자가 다르면
			{
				if (cnt[cur-'a']==1)
				{
					isContinuous = false;
					break;
				}
				cnt[cur - 'a'] = 1;
			}
			prev = cur;
		}
		if (isContinuous) ret++;
	}
	cout << ret;
}
	