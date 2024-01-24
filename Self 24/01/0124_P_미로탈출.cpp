/*
어 처음에는 bfs를 한번에 레버를 찾으면 여태 큐들을 초기화하고 그다음에 출구를 찾는 최적화를 진행했는데 

이렇게 말고 
시작지점 -> 레버 bfs 최단거리
레버 -> 출구 bfs 최단거리 
를 구해서 두개 다 구해질 수 있다면 횟수 return 아니면 -1 리턴 식으로 하는게 나을 듯 ㅇㅇ
*/
// #include <string>
// #include <vector>

// using namespace std;


// int solution(vector<string> maps) {
//     int answer = 0;
//     pair<int, int> startPoint;
//     pair<int, int> leverPoint;
//     pair<int, int> exitPoint;
    
//     for(int i = 0 ; i < maps.size();i++){
//         for(int j = 0; j < maps[i].length();j++){
//             if(maps[i][j] == 'S'){
//                 startPoint = {i,j};
//             }else if(maps[i][j] == 'L'){
//                 leverPoint = {i,j};
//             }else if(maps[i][j] == 'X'){
//                 exitPoint = {i,j};
//             }
//         }
//     }
    
//     return answer;
// }

// int bfs(pair<int, int> s, char e, vector<string>& maps){
    
// }


#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool visited[101][101] = {false,};
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
void resetVisited();

int solution(vector<string> maps) {
    int answer = 0;
    queue<tuple<int,int,int>> q;
    int startY, startX;
    bool isLever = false;
    
    for(int i = 0 ; i < maps.size(); i++){
        for(int j = 0; j < maps[i].length(); j++){
            if(maps[i][j] == 'S'){
                startY = i;
                startX = j;
            }
        }
    }
    
    q.push(make_tuple(startY,startX,0));
    
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop();
        visited[y][x] = true;
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            //범위 체크
            if(0 > ny || ny >= maps.size() || nx < 0 || nx >= maps[0].length())
                continue;
            
            //방문x, 벽이 아닐때 
            if(!visited[ny][nx] && maps[ny][nx] != 'X'){
                //여기서 레버+첫방문 체크
                if(maps[ny][nx] == 'L' && !isLever){
                    isLever = true;
                    //레버에 가장 먼저 도착했다는 것이니 모든것을 비워주고 가장 빠르게 exit을 찾는 경우의 수 찾기
                    while(!q.empty())
                        q.pop();
                    q.push(make_tuple(ny,nx,cnt+1));
                    resetVisited();
                    visited[ny][nx] = true;
                }else{
                    //탈출조건 만족
                    if(maps[ny][nx] == 'E' && isLever){
                        return cnt + 1;
                    }
                    //만족X -> exit,lever도 그냥 통로 중 하나임
                    visited[ny][nx] = true;
                    q.push(make_tuple(ny,nx,cnt+1));
                }
            }
        }
    }                     
    return -1;
}

void resetVisited(){
    for(int i = 0; i < 101;i++){
        for(int j = 0 ; j < 101; j++){
            visited[i][j] = false;
        }
    }
}