#include <iostream>
#include <algorithm>
using namespace std;

int map[51][51];
bool visited[51][51];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int t, n, m, k, x, y, bugnum;

void dfs(int y, int x) {
    visited[y][x] = true;  // 현재 위치 방문 처리
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 범위를 벗어나거나 방문했거나 배추가 없는 경우 건너뜀
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] || map[ny][nx] == 0)
            continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;  // 테스트 케이스 수 입력
    while (t--) {
        cin >> m >> n >> k;  // 배추밭의 가로, 세로 길이와 배추의 개수 입력
        
        fill(&map[0][0], &map[0][0] + 51 * 51, 0);      // 배추밭 초기화
        fill(&visited[0][0], &visited[0][0] + 51 * 51, false);  // 방문 여부 초기화
        bugnum = 0;  // 지렁이 수 초기화
        
        // 배추 위치 입력
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            map[y][x] = 1;  // 배추가 심어진 위치 표시
        }
        
        // 배추밭 탐색
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 방문하지 않았고 배추가 있는 경우 dfs 시작
                if (!visited[i][j] && map[i][j] == 1) {
                    dfs(i, j);
                    bugnum++;  // 배추 군집 하나 발견 후 지렁이 수 증가
                }
            }
        }
        
        cout << bugnum << "\n";  // 테스트 케이스마다 지렁이 수 출력
    }
    
    return 0;
}
