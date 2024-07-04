#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> original(n);
    vector<int> sorted(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
        sorted[i] = original[i];
    }
    
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    unordered_map<int, int> compress;
    for (int i = 0; i < sorted.size(); ++i) {
        compress[sorted[i]] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << compress[original[i]] << ' ';
    }
    cout << '\n';
    
    return 0;
}