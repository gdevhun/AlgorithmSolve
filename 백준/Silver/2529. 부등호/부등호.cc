#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int k;
bool visited[10];
char a[20];
vector<string> ret;
bool isAvailable(char x, char y, char op)
{
	if (x < y && op == '<') return true;
	if (x > y && op == '>') return true;
	return false;
}
void go(int idx,string num)
{
	if (idx==k+1)
	{
		ret.push_back(num);
		return;
	}
	for (int i=0; i<=9; i++)
	{
		if (visited[i]) continue;

		if (idx==0||isAvailable(num[idx-1], i+'0', a[idx-1]))
		{
			visited[i] = true;
			go(idx + 1, num + to_string(i));
			visited[i] = false;
		}
	}
	return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> k;
	for (int i=0; i<k; i++)
	{
		cin >> a[i]; 
	}
	go(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
	
	return 0;
}
