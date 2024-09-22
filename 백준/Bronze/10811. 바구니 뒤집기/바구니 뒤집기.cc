#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<int>basket(n);
    for (int i = 0; i < n; i++) {
        basket[i] = i + 1;
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        reverse(basket.begin() + i-1,basket.begin() + j);
    }
    for (int i = 0; i < n; i++) {
        cout << basket[i] << " ";
    }
    return 0;
}
