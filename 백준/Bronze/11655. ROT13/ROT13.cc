#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ROT13
    //abcdefghijklmnopqrstuvwxyz 26 a->97, 122
    //ABCDEFGHIJKLMNOPQRSTUVWXYZ 26 A->65, 90
    string str;

    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        //대문자인 경우 A->65 ~ Z->90
        if (str[i] >= 65 && str[i] <= 90) {
            if (str[i] + 13 > 90) str[i] = str[i] + 13 - 26;
            else str[i] = str[i] + 13;
        } 
        //소문자인 경우 a->97 ~ z->122
        else if (str[i] >= 97 && str[i] <= 122) {
            if (str[i] + 13 > 122)str[i] = str[i] + 13 - 26;
            else str[i] = str[i] + 13;
        }
        cout << str[i];
    }
    return 0;
}