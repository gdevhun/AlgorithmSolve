#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int ball = 1;
	int m;
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b; 
		if (ball == a) ball = b;
		else if (ball == b) ball = a;
	}
	cout << ball;
	return 0;
}