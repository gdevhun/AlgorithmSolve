#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }   // 종료 시간이 같으면 시작 시간이 빠른 순으로 정렬
    return a.second < b.second; // 종료 시간이 빠른 순으로 정렬
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int>>vec;
    int n, start, end;
    int last_end_time, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        vec.push_back({ start ,end }); //시작~종료
    }
    sort(vec.begin(), vec.end(),compare); //오름차순으로 나열

    //for (auto& elem : vec) cout << elem.first << " " << elem.second << endl;

    last_end_time = vec[0].second;
    cnt++;

    for (int i = 1; i < n; i++) {
        if (last_end_time <= vec[i].first) { //만약 끝나는 시간이 다음 회의의 시작시간보다 작거나 같으면
            last_end_time = vec[i].second;
            cnt++;
        }
        else {
            continue;
        }
    }
    cout << cnt;
    return 0;
}