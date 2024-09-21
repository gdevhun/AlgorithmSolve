#include <iostream>
#include <algorithm>

using namespace std;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //abcdefghijklmnopqrstuwxyz 26 A->65, a->97
    bool found = false;
    string name;
    int n;
    cin >> n;
    while (n--) {
        cin >> name;
        cnt[(name[0] - 'a')]++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << char(i+97);
            found = true;
        }
    }
    if (!found) cout << "PREDAJA";
    return 0;
}