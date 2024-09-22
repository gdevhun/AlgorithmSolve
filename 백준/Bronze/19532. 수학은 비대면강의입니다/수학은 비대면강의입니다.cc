#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int y = (c * d - a * f) / (b * d - a * e);
    int x = (c * e - b * f) / (a * e - b * d);
    //c = a * x + b * y;
    //f = d * x + e * y;

    cout << x << " "<< y;
    return 0;
}
