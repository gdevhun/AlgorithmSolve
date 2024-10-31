#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vec;
int n, m;
int map[101][101];
bool visited[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int cnt, cnt2;

void dfs(int y,int x) {
    visited[y][x] = true;
    if (map[y][x] == 1) {
        vec.push_back({ y,x });
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (visited[ny][nx] || ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }
        dfs(ny, nx);
    }
    return;
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
    
    while (1) {

        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        vec.clear();
        dfs(0, 0);
        cnt2 = vec.size();

        for (pair<int, int> b : vec) {
            map[b.first][b.second] = 0;
        }

        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] != 0) flag = 1; //치즈가있으면 flag=1
            }
        }
        cnt++;
        if (!flag) break;
    }
    cout << cnt << "\n" << cnt2 << "\n";

    return 0;
}