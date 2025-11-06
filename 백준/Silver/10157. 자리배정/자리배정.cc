#include<iostream>
#include <string>
#include <vector>
using namespace std;
bool visited[1001][1001];
int c, r, k;

int dy[4] = { 1, 0, -1, 0 };   
int dx[4] = { 0, 1, 0, -1 };  

int main()
{
    cin >> c >> r >> k;

    if (k > c * r) {
        cout << "0\n";
        return 0;
    }

    int x = 1, y = 1;  
    int dir = 0;       
    visited[y][x] = true;

    // k=1이면 시작 위치가 답
    if (k == 1) {
        cout << x << " " << y << "\n";
        return 0;
    }

    int cnt = 1;  // 현재까지 배정한 좌석 수

    while (cnt < k) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        //  방향 전환
        if (ny < 1 || nx < 1 || ny > r || nx > c || visited[ny][nx]) {
            dir = (dir + 1) % 4;
            continue;
        }

        // 이동
        y = ny;
        x = nx;
        visited[y][x] = true;
        cnt++;

        // k번째 좌석 도달
        if (cnt == k) {
            cout << x << " " << y << "\n";
            break;
        }
    }

    return 0;
}
	