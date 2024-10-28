#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[8][8];
int visited[8][8];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int max_safe_area = 0;

bool checkRange(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < m);
}

// 바이러스 확산 (DFS)
void virusdfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (checkRange(ny, nx) && map[ny][nx] == 0 && !visited[ny][nx]) {
            visited[ny][nx] = true;
            map[ny][nx] = 2;
            virusdfs(ny, nx);
        }
    }
}

// 안전 영역 계산
int getSafeArea() {
    int safe_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) safe_area++;
        }
    }
    return safe_area;
}

// 벽 세우기
void buildWall(int count) {
    if (count == 3) {
        // visited 배열 초기화
        fill(&visited[0][0], &visited[0][0] + 8 * 8, false);

        // 바이러스 확산
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 2 && !visited[i][j]) {
                    virusdfs(i, j);
                }
            }
        }

        // 안전 영역 최댓값 갱신
        max_safe_area = max(max_safe_area, getSafeArea());

        // 바이러스 확산 상태 원래대로 복구
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] && map[i][j] == 2) {
                    map[i][j] = 0;  // 바이러스가 퍼진 위치를 빈 칸으로 복구
                }
            }
        }
        return;
    }

    // 빈 칸에 벽 세우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;  // 벽 설치
                buildWall(count + 1);
                map[i][j] = 0;  // 원래 상태로 복구
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    buildWall(0);
    cout << max_safe_area << "\n";

    return 0;
}

