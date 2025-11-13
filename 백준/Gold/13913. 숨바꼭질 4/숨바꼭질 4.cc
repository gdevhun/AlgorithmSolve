#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int visited[100001];
int parent[100001];  // 경로 추적용

void bfs()
{
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    parent[n] = -1;  // 시작점은 부모 없음

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)  // 동생 찾음
        {
            break;
        }

        // 3가지 이동 방법
        int next[3] = { cur - 1, cur + 1, cur * 2 };

        for (int i = 0; i < 3; i++)
        {
            int nx = next[i];

            // 범위 체크
            if (nx < 0 || nx > 100000) continue;

            // 방문하지 않은 곳
            if (!visited[nx])
            {
                visited[nx] = visited[cur] + 1;
                parent[nx] = cur;  // 부모 기록
                q.push(nx);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    // 예외 처리: 이미 같은 위치
    if (n == k)
    {
        cout << 0 << "\n";
        cout << n << "\n";
        return 0;
    }

    bfs();

    // 시간 출력 (visited는 1부터 시작했으므로 -1)
    cout << visited[k] - 1 << "\n";

    // 경로 역추적
    vector<int> path;
    int cur = k;

    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    // 역순이므로 뒤집기
    reverse(path.begin(), path.end());

    // 경로 출력
    for (int p : path)
    {
        cout << p << " ";
    }

    return 0;
}
	