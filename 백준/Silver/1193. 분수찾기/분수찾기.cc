#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;
    
    int n = 1;
    int sum = 1;
    
    // 대각선 번호를 찾는다.
    while (sum < X) {
        n++;
        sum += n;
    }
    
    // 대각선에서의 위치를 계산한다.
    int diff = sum - X;
    int numerator, denominator;
    
    if (n % 2 == 0) {
        numerator = n - diff;
        denominator = 1 + diff;
    } else {
        numerator = 1 + diff;
        denominator = n - diff;
    }
    
    cout << numerator << "/" << denominator << endl;
    
    return 0;
}