/*
단속 카메라

한번은 단속용 카메라를 만나도록해야하는데 최소 갯수 구하기
주어지는 진입진출지점 숫자도 포함

음... 시작지점을 기준으로 정렬을 한다. (오름차순)
그 다음 첫번째의 끝나는 부위까지 다른것을 점검한다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> & b){
    if(a[0] != b[0])
    {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int location = -30001; // 위치 기준으로 만약 그것 범위 내라면 바로 스킵
    
    sort(routes.begin(),routes.end(),compare);
    
    for(int i = 0; i < routes.size();i++){
        //3번케이스
        if(routes[i][0] > location){
            location = routes[i][1];
            answer++;
        }else{
            //2번케이스
            if(routes[i][1] <= location)
                location = routes[i][1];
            //1번케이스는 location값 유지.
        }
    }
    return answer;
}