#include <iostream>
#include <vector>
using namespace std;
vector<int>vec;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
     
    int n;
    int total = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    for (auto it = vec.begin(); it != vec.end(); it++) {
        total += *it;
    }
    cout << total;
    
}