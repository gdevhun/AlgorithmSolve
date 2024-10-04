#include <iostream>
#include <algorithm>
using namespace std;


int map[51][51];
bool visited[51][51];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int t, n, m, k, x, y, bugnum;
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (visited[ny][nx]||map[ny][nx]==0) continue;
        dfs(ny, nx);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;

        fill(&map[0][0], &map[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        bugnum = 0;

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            map[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && map[i][j] == 1) {
                    dfs(i, j);
                    bugnum++;
                }
            }
        }
        cout << bugnum << "\n";
    }

    return 0;
}