/*
게임 맵 최단거리

누가 봐도 bfs로 풀어라! 하고 주는 문제 같은데
0,0에서 시작하고 n-1,m-1일때 도착
*/
#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    //동서남북
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    queue<pair<int,int>> q;
    int n = maps.size(); //행
    int m = maps[0].size(); //열
    int visited[100][100] ={0,};
    
    q.push(make_pair(0,0));
    visited[0][0] = 1;
    
    while(!q.empty()){
        //흔한 bfs방법으로 y,x를 뽑아내고 pop
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        //동서남북에 대해서 갈 수 있는지에 대한 체킹
        for(int i = 0; i < 4; i ++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(maps[ny][nx] == 1&& visited[ny][nx] == 0){
                    q.push(make_pair(ny,nx));
                    visited[ny][nx]= visited[y][x] + 1;
                    if(ny == n - 1 && nx == m - 1)
                        return visited[ny][nx];
                }
            }
        }
    }
    return -1;
}


