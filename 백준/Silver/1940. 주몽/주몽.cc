#include <iostream>
#include <string>
using namespace std;
int material[150001];
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> material[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (material[i] + material[j] == m) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}