#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int asize, bsize, temp_elem;
    int cnt = 0;
    cin >> asize >> bsize;
    set<int>aset;
    set<int>bset;

    while (asize--) {
        cin >> temp_elem;
        aset.insert(temp_elem);
    }
    while (bsize--) {
        cin >> temp_elem;
        bset.insert(temp_elem);
    }
    for (const auto &elem : aset) {
        if (bset.find(elem) == bset.end()) {
            cnt++;
        }
    }
    for (const auto& elem : bset) {
        if (aset.find(elem) == aset.end()) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}