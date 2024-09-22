#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string>alphaSet;
    string s;
    cin >> s;
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            temp += s[j];
            alphaSet.insert(temp);
        }
        temp = "";
    }
    cout << alphaSet.size();
}
