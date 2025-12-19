#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int visited[101][101];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int n,m; //y,x

void bfs(int y,int x, const vector<vector<int>> &maps){
    queue<pair<int,int>> que;
    visited[y][x]=1;
    que.push({y,x});
    
    while(!que.empty()){
        int cy=que.front().first;
        int cx=que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]) continue;
            if(maps[ny][nx]==0) continue;
            visited[ny][nx]=visited[cy][cx]+1;
            que.push({ny,nx});
        }
    }
    
}
int solution(vector<vector<int>> maps)
{
    n=maps.size(); //5
    m=maps[0].size(); //5

    bfs(0,0,maps);
    
    //debug
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<visited[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
    
    if(visited[n-1][m-1]==0) return -1;
    else return visited[n-1][m-1];
}