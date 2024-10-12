#include<iostream>
#include<string>
using namespace std;
string str;

bool isVowel(char idx) {
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	bool firstCase = false;  //모음aeiou 하나 반드시포함
	bool secondCase = false; //모음 3개 혹은 자음3개 연속으로오면안됨
	bool thirdCase = false; //같은 글자가 연속적으로 두번 오면 안되나 ee,oo는 허용
	while (1) {
		cin >> str;
		if (str == "end") break;

		firstCase = false;  
		secondCase = false; 
		thirdCase = false;
		char prev = 0; //이전문자저장
		int ConsCnt = 0, VowCnt = 0; //모음 자음 연속 체크를 위한 변수

		for (int i = 0; i < str.size(); i++) {
			char idx = str[i]; //인덱스추출

			if (isVowel(idx)) {  //모음이 들어왔을 때
				firstCase = true; VowCnt++; ConsCnt = 0;
			}
			else { //자음이 들어왔을 때
				ConsCnt++; VowCnt = 0;
			}

			if (ConsCnt == 3 || VowCnt == 3) {
				secondCase = true;  //모음자음3개연속오는케이스체크
				break;
			}

			if (prev == idx && (idx != 'e' && idx != 'o')) {
				thirdCase = true; //전문자와 연속인데, e,o는 아닌경우
				break;
			}
			prev = idx;
		}
		if (!firstCase || secondCase || thirdCase) {
			cout << "<" << str << ">" << " is not acceptable." << "\n";
		}
		else {
			cout << "<" << str << ">" << " is acceptable." << "\n";
		}
	}

	return 0;
}