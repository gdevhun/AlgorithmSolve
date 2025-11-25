#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>vec(3);
	for (int i=0; i<3; i++)
	{
		cin >> vec[i];
	}
	if (vec[0] == 60 && vec[1] == 60 && vec[2] == 60) cout << "Equilateral";
	else if (vec[0] + vec[1] + vec[2] == 180)
	{
		if (vec[0] == vec[1] || vec[0] == vec[2] || vec[1] == vec[2]) cout << "Isosceles";
		else if (vec[0] != vec[1] && vec[1] != vec[2]) cout << "Scalene";
	}
	else cout << "Error";
	return 0;
}