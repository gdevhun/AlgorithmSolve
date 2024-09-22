#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, elem;
    int line = 1;
    cin >> n;
    
    stack<int> st;
    
    while (n--) {
        cin >> elem;
        if (line == elem) {
            line++;
        } else {
            st.push(elem);
        }
        
        while (!st.empty() && st.top() == line) {
            st.pop();
            line++;
        }
    }
    
    if (st.empty()) {
        cout << "Nice";
    } else {
        cout << "Sad";
    }
    
    return 0;
}