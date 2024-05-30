#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	map<string, string, greater<string>> map;
	int n;
	string name, work;
	cin >> n;
	while (n--) {
		cin >> name >> work;
		if (map.find(name)!=map.end()) { //근무자 동명이인을 찾지못하면 end리턴.
			map.erase(name);
			map.insert(make_pair(name, work));
		}
		map.insert(make_pair(name,work));
	}
	for (auto iter = map.begin(); iter != map.end(); iter++) {
		if (iter->second == "enter") {
			cout << iter->first << " ";
		}
	}
}