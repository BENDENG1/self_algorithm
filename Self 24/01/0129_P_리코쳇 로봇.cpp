/*
보드 게임

4각 이동 -> 미끄러짐은 한번의 이동
장애물이나 맨 끝에 부딪힐 때 까지 미끄러져 이동 하는 것

R -> 처음 위치 / D -> 장애물 위치 / G -> 목표지점

*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<string>& board);

int answer = -1;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visited[101][101] = {false,};

struct point{
    int y;
    int x;
    int cnt;
};
queue<point> q;

int solution(vector<string> board) {
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[i].length(); j++){
            if(board[i][j] == 'R'){
                q.push({i,j,0});
                visited[i][j] = true;
            }
                
        }
    }
    bfs(board);
    
    
    return answer;
}


void bfs(vector<string>& board){
    
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();
        
        if(board[y][x] == 'G'){
            answer = cnt;
            return;
        }
        
        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= board.size() || nx < 0 
               || nx >= board[0].length() || board[ny][nx] == 'D')
                continue;
            
            while(1){
                ny += dy[i];
                nx += dx[i];
                
                if(ny < 0 || ny >= board.size() || nx < 0 
               || nx >= board[0].length() || board[ny][nx] == 'D'){
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
            
            if(visited[ny][nx]) continue;
            q.push({ny,nx,cnt+1});
            visited[ny][nx] = true;
        }
    }

}