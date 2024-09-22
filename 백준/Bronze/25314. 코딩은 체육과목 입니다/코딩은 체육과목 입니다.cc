#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,time;
    cin >> n;
    time = n / 4;
    while (time--) {
        cout << "long ";
    }
    cout << "int";
    return 0;
}