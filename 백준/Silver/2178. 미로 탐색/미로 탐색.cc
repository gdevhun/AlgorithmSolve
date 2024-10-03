#include <iostream>
#include <queue>
using namespace std;

const int max_n = 104;
int dy[4] = { 1, 0,-1, 0 };
int dx[4] = { 0,-1, 0, 1 };
int n, m, a[max_n][max_n];
int visited[max_n][max_n];
int y, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            a[i][j] = str[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty()) {  // 큐가 비어있지 않을 때까지 반복
        y = q.front().second;
        x = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ nx, ny });
        }
    }

    cout << visited[n - 1][m - 1] << "\n";
    return 0;
}