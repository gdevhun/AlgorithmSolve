#include <iostream>
using namespace std;
int basket[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 100; i++) {
        basket[i] = i;
    }
    int n, m;
    cin >> n >> m;
    while (m--) {
        int i, j, temp;
        cin >> i >> j;
        temp = basket[i];
        basket[i] = basket[j];
        basket[j] = temp;
    }
    for (int i = 1; i <= n; i++) {
        cout << basket[i] << " ";
    }
}
