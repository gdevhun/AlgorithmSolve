#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[101][101];
bool visited[101][101];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int m, n, k, cnt, eacharea;

void dfs(int y, int x) {
    visited[y][x] = true;
    eacharea++;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 경계 체크 (nx는 열, ny는 행이므로 m, n으로 체크)
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (map[ny][nx] == 1 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> areaContainer;
    fill(&map[0][0], &map[0][0] + 101 * 101, 0);
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

    cin >> m >> n >> k;
    
    // 직사각형 채우기
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // 직사각형의 좌표에 맞추어 내부를 1로 채우기
        for (int x = a; x < c; x++) {
            for (int y = b; y < d; y++) {
                map[y][x] = 1;
            }
        }
    }

    // DFS를 통해 영역 탐색
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 0) {
                eacharea = 0;
                dfs(i, j);
                areaContainer.push_back(eacharea);
                cnt++;
            }
        }
    }

    // 결과 출력
    cout << cnt << "\n";
    sort(areaContainer.begin(), areaContainer.end());  // 넓이를 오름차순 정렬
    for (auto num : areaContainer) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}