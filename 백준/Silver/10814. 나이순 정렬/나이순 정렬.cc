#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool compair(pair<int, pair<int, string>> a,
	pair<int, pair<int, string>> b) {
	if (a.second.first == b.second.first) //나이같으면
	  return a.first< b.first; //가입순으로
	//아니면 나이 순
	else return a.second.first < b.second.first;
}
int main() {
	vector<pair<int, pair<int, string>>> vec;
	int n; //회원의 수
	/*
	첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 
	나이가 같으면 가입한 순으로 한 줄에 한 명씩 
	나이와 이름을 공백으로 구분해 출력한다.
	*/
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tn; string ts;
		cin >> tn >> ts;
		vec.push_back(make_pair(i, make_pair(tn, ts)));
	}
	sort(vec.begin(),vec.end(),compair);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second.first << " " << vec[i].second.second << "\n";
	}
}