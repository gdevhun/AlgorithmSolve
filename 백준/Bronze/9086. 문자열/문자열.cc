#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int T;
    string str;
    cin >> T;
    while (T--) {
        cin >> str;
        cout << str[0] << str[str.size() - 1] << "\n";
    }
    
}