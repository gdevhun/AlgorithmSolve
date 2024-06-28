#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 별도의 연산과정이 들어가지 않으므로 long long 자료형은 필요없을 것으로 판단됩니다.
vector<int> v;

int binary_search(int s, int e, int val)
{
	if (s == e)
		return v[s] == val; // v[e] == val과 동치 만약 v[s] | v[e] != val이라고 하면 탐색을 했는데도 다 찾지 못하였으므로 0을 리턴
	int mid = (s + e) / 2;
	if (v[mid] == val) // 찾으려는 수와 같다면
		return 1;
	if (v[mid] > val)
		return binary_search(s, mid, val);
	return binary_search(mid + 1, e, val);
}

int main(int argc, char* argv[])
{
	// Fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, M;
	cin >> N;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		cout << binary_search(0, N - 1, x) << " ";
	}
	cout << '\n';
	return 0;
}