#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	while (true)
	{
		vector<int> vec;
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
		sort(vec.begin(), vec.end());

		if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0) break;
		if (vec[2]>=vec[0] + vec[1])
		{
			cout << "Invalid" << "\n";
			continue;
		}
		if (vec[0] == vec[1] && vec[1] == vec[2])
		{
			cout << "Equilateral" << "\n";
			continue;
		}
		if ((vec[0] == vec[1] && vec[1] != vec[2]) || (vec[1] == vec[2] && vec[1] != vec[0])
			|| (vec[0] == vec[2] && vec[0] != vec[1]))
		{
			cout << "Isosceles" << "\n";
			continue;
		}
		if (vec[0] != vec[1] && vec[1] != vec[2])
		{
			cout << "Scalene" << "\n";
			continue;
		}
	}
    
    return 0;
}