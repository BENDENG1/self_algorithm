/*
공원 산책 -> 지나다니는 길 o 장애물 x
"방향 거리" , "방향 거리" -> 이런식

결국 명령을 했을때 갈 수 있는지에 대한 체크를 하면 된다. 
못가면 패스 갈 수 있다면 통과
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int boundaryCheck(vector<string>park,int direction, int move); //park, 방향, 이동횟수

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int y =0, x= 0; //시작 좌표설정
    int mapY = park.size(); //맵 y크기
    int mapX = park[0].size(); //맵 x크기
    
    for(int i  = 0; i < mapY;i++){
        for(int j = 0; j < mapX;j++){
            if(park[i][j] == 'S'){
                y=i;
                x=j;
            }
        }
    }
    
    for(int i = 0; i < routes.size();i++){
        int step = (routes[i][2] - '0'); // step의 크기
        int cantMove = 0; // 움직이지 못하면 1 가능 -> 0
        if(routes[i][0] == 'E'){
            if(x + step < mapX){
                for(int j = x;j <= x + step;j++){
                    if(park[y][j]=='X')
                        cantMove = 1;
                }
                if(cantMove == 0)
                    x += step;
            }
        }else if (routes[i][0] == 'W'){
            if(0 <=x - step){
                for(int j = x;j >= x - step;j--){
                    if(park[y][j]=='X')
                        cantMove = 1;
                }
                if(cantMove == 0)
                    x -= step;
            }
        }else if (routes[i][0] == 'S'){
            if(y + step < mapY){
                for(int j = y;j <= y + step;j++){
                    if(park[j][x]=='X')
                        cantMove = 1;
                }
                if(cantMove == 0)
                    y += step;
            }
            
        }else if (routes[i][0] == 'N'){
            if(0 <= y - step){
                for(int j = y;y-step <= j;j--){
                    if(park[j][x]=='X')
                        cantMove = 1;
                }
                if(cantMove == 0)
                    y -= step;
            }
        }
    }
    
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}

