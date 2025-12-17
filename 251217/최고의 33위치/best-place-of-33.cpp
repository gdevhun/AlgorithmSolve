#include <iostream>
#include <algorithm>
using namespace std;
int maxnum;
int N;
int grid[20][20];
int visited[20][20];
int dy[8]={0,0,1,-1,1,-1,1,-1};
int dx[8]={1,-1,0,0,1,-1,-1,1};

void dfs(int y,int x){
    int cnt=0;
    if(grid[y][x]==1) cnt=1;
    for(int i=0; i<8; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N) return;
        if(grid[ny][nx]==1) cnt++;
    }
    maxnum=max(maxnum,cnt);
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dfs(i,j);
        }
    }
    cout<<maxnum;
    return 0;
}
