#include <iostream>
using namespace std;
int basket[101] = { 0, };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int t = i - 1; t < j; t++) {
            basket[t] = k;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << basket[i] << " ";
    }
}