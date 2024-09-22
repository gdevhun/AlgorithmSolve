#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	char vec[5][15] = {};
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			vec[i][j]=str[j];
		}
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (vec[j][i] == '\0') continue;
			cout << vec[j][i];
		}
	}
}
