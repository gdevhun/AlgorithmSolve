#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 비교 함수: 길이가 같으면 사전순, 그렇지 않으면 길이순으로 정렬
bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, string>> vec;
    string str;

    while (n--) {
        cin >> str;
        vec.push_back({str.size(), str});
    }

    // 정렬
    sort(vec.begin(), vec.end(), compare);

    // 중복 제거
    vec.erase(unique(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second == b.second;
    }), vec.end());

    // 출력
    for (const auto& p : vec) {
        cout << p.second << '\n';
    }

    return 0;
}