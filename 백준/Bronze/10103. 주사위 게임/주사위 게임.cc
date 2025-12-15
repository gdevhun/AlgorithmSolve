#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
#include <set>
using namespace std;
int total_cy = 100;
int total_sd = 100;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	int score_cy, score_sd;
	cin >> n;
	while (n--)
	{
		//창영, 상덕
		cin >> score_cy >> score_sd;
		if (score_cy>score_sd)
		{
			total_sd -= score_cy;
		}
		else if (score_cy<score_sd)
		{
			total_cy -= score_sd;
		}
	}
	cout << total_cy << "\n" << total_sd;
	return 0;
}
