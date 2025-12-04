#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int sx, sy, tx, ty;
char map[301][301];
bool visited[301][301];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int bfs(int sy, int sx)
{
    queue<pair<int, int>> q, nextq;
    int jump = 0;

    q.push({ sy, sx });

    while (1)
    {
        jump++;

        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        //memset(visited, 0, sizeof(visited));

        while (!q.empty())
        {
            int cy = q.front().first;
            int cx = q.front().second;
  
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = 1;

                // 목표 도착
                if (map[ny][nx] == '#')
                    return jump;

                if (map[ny][nx] == '0') {
                    q.push({ ny,nx });
                }
                else if (map[ny][nx] == '1') {
                    nextq.push({ ny,nx });
                }
            }
        }

        // 점프 후 이동 가능한 큐로 교체
        q = nextq;
        nextq = queue<pair<int, int>>();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> sy >> sx >> ty >> tx;
    sy--, sx--, ty--, tx--;

    for (int i = 0; i < n; i++) {
        string input;
    	cin >> input;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = input[j];
        }
    }

    cout << bfs(sy, sx);
}