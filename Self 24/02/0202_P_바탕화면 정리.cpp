/*
바탕화면 정리

wallpaper 0,0시작 -> 빈칸 . 파일은 # 

드래그, 삭제 가능 최소한의 이동거리 

최소한의 드래그 시작지점과 끝지점의 좌표를 리턴

그냥 최솟값 최댓값 찾으면 끝 ㅇㅇ

*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int sy = wallpaper.size();
    int sx = wallpaper[0].length();
    int ey = 0;
    int ex = 0;
    
    for(int i = 0 ; i < wallpaper.size(); i++){
        for(int j = 0 ; j < wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                if(i <= sy)
                    sy = i;
                if(j <= sx)
                    sx = j;
                if(i >= ey)
                    ey = i + 1;
                if(j >= ex)
                    ex = j + 1;
            }
        }
    }
    
    answer.push_back(sy);
    answer.push_back(sx);
    answer.push_back(ey);
    answer.push_back(ex);
    
    return answer;
}