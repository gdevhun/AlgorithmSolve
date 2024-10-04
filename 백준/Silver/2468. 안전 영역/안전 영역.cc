#include <iostream>
#include <algorithm>
using namespace std;


int map[101][101];
bool visited[101][101];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int n;
int height, maxnum;
void dfs(int y, int x, int level) {

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
        if (map[ny][nx] <= level || visited[ny][nx]==1) continue;
        dfs(ny, nx, level);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //높이는 1~100

    cin >> n;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            height = max(height, map[i][j]);
        }
    }
    for (int level = 0; level <= height; level++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        int safeZones = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && map[i][j] > level) {
                    dfs(i, j, level);
                    safeZones++; // 안전한 영역 하나 발견
                }
            }
        }
        maxnum = max(maxnum, safeZones);
    }

    cout << maxnum << "\n";
    return 0;
}