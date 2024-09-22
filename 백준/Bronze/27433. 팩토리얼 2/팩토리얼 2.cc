#include <iostream>

using namespace std;

long int fac(long long int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int num;
    cin >> num;
    cout << fac(num);

    return 0;
}