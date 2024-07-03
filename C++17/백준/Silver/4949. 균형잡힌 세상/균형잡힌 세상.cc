#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;

    while (1) {
        getline(cin, str);
        if (str == ".") break;

        stack<char> stack;
        bool flag = true;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                stack.push(str[i]);
            }
            else if (str[i] == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag && stack.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}
