#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string str, ret;
vector<string> vec;
void zerofunc() {
	while (1) {
		if (ret.size() && ret.front() == '0') {
			ret.erase(ret.begin());
		}
		else break;	
	}
	if (ret.size() == 0) ret = "0";

	vec.push_back(ret);
	ret = "";
}
bool cmp(string a, string b) {
	if (a.size() == b.size()) { //길이가 같으면
		return a < b;  //사전순 비교 작은 문자열 앞  ex) 23 vs 12 이면 12가 오도록
	}
	return a.size() < b.size(); //길이가 다르면 길이가 짧은 문자열이 앞에 오게 ex) 123 vs 45 45가 먼저오도록
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		ret = "";
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] < 65) 	ret += str[j]; //숫자라면 A->65 a->97
			else if(ret.size()) zerofunc();
		}
		if (ret.size()) zerofunc();
	}
	sort(vec.begin(), vec.end(), cmp);
	for (string i : vec) cout << i << "\n";
	return 0;
}