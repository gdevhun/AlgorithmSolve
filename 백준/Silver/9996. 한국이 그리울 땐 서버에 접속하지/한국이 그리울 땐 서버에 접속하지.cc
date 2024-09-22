#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; string pattern, inputstr;
    cin >> n >> pattern;

    int star_idx = pattern.find("*");
    string prefix = pattern.substr(0, star_idx);
    string suffix = pattern.substr(star_idx + 1);

    for (int i = 0; i < n; i++) {
        cin >> inputstr;
        if (prefix.size() + suffix.size() > inputstr.size()) cout << "NE" << '\n';
        else {
            if (prefix == inputstr.substr(0, prefix.size()) && suffix == inputstr.substr(inputstr.size() - suffix.size())) cout << "DA" << '\n';
            else cout << "NE" << '\n';
        }
    }

    return 0;
}