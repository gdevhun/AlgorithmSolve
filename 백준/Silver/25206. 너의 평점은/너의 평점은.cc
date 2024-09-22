#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	float average;
	string grade;
	float totalaverage = 0;
	int totalscore = 0;

	for (int i = 0; i < 20; i++) {
		cin >> str >> average >> grade;
		if (grade == "P") continue;
		
		if (grade == "A+") {
			totalaverage+=average * 4.5;
		}
		else if (grade == "A0") {
			totalaverage += average * 4.0;
		}
		else if (grade == "B+") {
			totalaverage += average * 3.5;
		}
		else if (grade == "B0") {
			totalaverage += average * 3.0;
		}
		else if (grade == "C+") {
			totalaverage += average * 2.5;
		}
		else if (grade == "C0") {
			totalaverage += average * 2.0;
		}
		else if (grade == "D+") {
			totalaverage += average * 1.5;
		}
		else if (grade == "D0") {
			totalaverage += average * 1.0;
		}
		else if (grade == "F") {
			totalaverage += average * 0.0;
		}
		totalscore += average;
	}
	cout << totalaverage / totalscore;
}