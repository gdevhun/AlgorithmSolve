#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int N;
	cin >> N;
    int num;
	for (int i = 0; i < N;  i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i<N; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}