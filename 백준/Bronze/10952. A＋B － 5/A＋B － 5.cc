#include <iostream>
#include <vector>
using namespace std;
vector<int>vec;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num1, num2;
    while (1) {
        cin >> num1 >> num2;

        if (num1 == 0 && num2 == 0) break;

        vec.push_back(num1);
        vec.push_back(num2);

        if (vec.size()) {
            cout << vec.front() + vec.back() << endl;
        }
        vec.pop_back();
        vec.pop_back();
    }
    
}