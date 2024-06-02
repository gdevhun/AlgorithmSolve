#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int cnt = 0;
    string str;
    getline(cin, str);
    // 문자열이 비어있는 경우 0을 출력하고 종료
    if (str.empty()) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') cnt++;
    }

    // 문자열의 시작과 끝이 공백인 경우를 고려해서 조정
    if (str[0] == ' ') cnt--;
    if (str[str.size() - 1] == ' ') cnt--;

    // 단어 개수는 공백 개수 + 1
    cout << cnt + 1 << "\n";
    return 0;
}