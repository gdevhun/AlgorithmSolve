#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dist[51][51];
int map[51][51];
int dy[8] = { 0, 0, 1,-1, -1, 1,-1, 1 };
int dx[8] = { 1,-1, 0, 0, -1, 1, 1,-1 };
int n, m;

int bfs(int y, int x)
{
    queue<pair<int, int>> que;
    dist[y][x] = 0;  // 시작점은 거리 0
    que.push({y, x});
    
    while (!que.empty())
    {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();  // ← 이게 빠져있었습니다!
        
        // 상어를 만나면 거리 반환
        if (map[cy][cx] == 1)
        {
            return dist[cy][cx];
        }
        
        for (int i = 0; i < 8; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (dist[ny][nx] != -1) continue;  // 이미 방문
            
            dist[ny][nx] = dist[cy][cx] + 1;
            que.push({ny, nx});
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)  // n행
    {
        for (int j = 0; j < m; j++)  // m열
        {
            cin >> map[i][j];
        }
    }
    
    int maxret = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0) 
            {
                fill(&dist[0][0], &dist[0][0] + 51 * 51, -1);
                int safeDist = bfs(i, j);
                maxret = max(maxret, safeDist);
            }
        }
    }
    
    cout << maxret;
    return 0;
}