#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<char>v;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		v.push_back(str[i]);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}