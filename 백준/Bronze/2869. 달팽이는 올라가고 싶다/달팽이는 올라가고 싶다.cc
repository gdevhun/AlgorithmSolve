
#include <iostream>
#include <cmath> // ceil 함수 포함
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, v;
    cin >> a >> b >> v;

    int days = (v - b - 1) / (a - b) + 1;
    cout << days << "\n";
    
    return 0;
}