#include <iostream>
#include <string>
#include <map>
using namespace std;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int testnum, n;
	cin >> testnum;
	for (int i = 0; i < testnum; i++) {
		map<string, int>mymap;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			mymap[b]++;
		}
		int ret = 1;
		for (auto c : mymap) {
			ret *= c.second + 1;
		}
		ret--;
		cout << ret << "\n";
	}
	
}