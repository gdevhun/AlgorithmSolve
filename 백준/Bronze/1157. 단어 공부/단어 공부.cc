#include <iostream>
#include <string>
#include <cctype>  // tolower, toupper 함수 사용
using namespace std;

int cnt[26]; // 대소문자 구분 없이 26개의 알파벳만 처리

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    // 모든 문자를 소문자로 변환해서 카운트
    for (int i = 0; i < str.size(); i++) {
        char ch = tolower(str[i]); // 소문자로 변환
        cnt[ch - 'a']++; // a는 0번 인덱스에 해당
    }

    bool isMulti = false;
    int maxCount = 0;
    int answerIdx = 0;

    // 가장 많이 사용된 알파벳 찾기
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > maxCount) {
            maxCount = cnt[i];
            answerIdx = i;
            isMulti = false; // 새로운 최대값 발견 시 중복 여부 초기화
        }
        else if (cnt[i] == maxCount) {
            isMulti = true; // 최대값과 같은 경우가 있을 때 중복 처리
        }
    }

    if (isMulti) {
        cout << "?\n";
    }
    else {
        // 정답을 대문자로 출력
        cout << (char)(answerIdx + 'A') << '\n';
    }

    return 0;
}