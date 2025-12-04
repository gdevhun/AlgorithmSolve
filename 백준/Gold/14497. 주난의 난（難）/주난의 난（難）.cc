#include <bits/stdc++.h>
using namespace std;

int n, m;
int sx, sy, tx, ty;
char mp[301][301];
bool visited[301][301];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int bfs(int sy, int sx)
{
    queue<pair<int,int>> q, nextq;
    int jump = 0;

    q.push({sy, sx});

    while (1)
    {
        jump++;

        memset(visited, 0, sizeof(visited));

        while (!q.empty())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i=0; i<4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = 1;

                // 목표 도착
                if (mp[ny][nx] == '#') 
                    return jump;

                if (mp[ny][nx] == '0') {
                    q.push({ny,nx});
                }
                else if (mp[ny][nx] == '1') {
                    nextq.push({ny,nx});
                }
            }
        }

        // 점프 후 이동 가능한 큐로 교체
        q = nextq;
        nextq = queue<pair<int,int>>();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> sy >> sx >> ty >> tx;
    sy--, sx--, ty--, tx--;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cin >> mp[i][j];
    }

    cout << bfs(sy, sx);
}