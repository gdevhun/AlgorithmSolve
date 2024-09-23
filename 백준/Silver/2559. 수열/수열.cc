#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    long long day[100001];
    for (int i = 0; i < N; i++) {
        cin >> day[i];
    }

    long long max_sum = 0;
    long long current_sum = 0;

    // 처음 K일의 온도 합을 계산
    for (int i = 0; i < K; i++) {
        current_sum += day[i];
    }
    
    max_sum = current_sum;

    // 슬라이딩 윈도우
    for (int i = K; i < N; i++) {
        current_sum += day[i] - day[i - K]; // 현재 합에서 가장 오래된 온도를 빼고 새 온도를 더함
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << "\n";
    return 0;
}