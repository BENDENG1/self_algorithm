/*
결국 개구간인거는 정수의 형태로 나눌 수 없다는 것이 문제의 특징
결국 실수의 형태로 잘라내야 하는건데

시작 인덱스와 끝의 인덱스가 일단 어떤것의 안에 있다? -> 무조건 안의 인덱스 안
걸쳐 있다(어느정도 포함) -> 시작구간~ 끝구간의 비교를 통해 그 안에 설정
시작값과 끝값이 같은 번호 -> 이것은 개구간이므로 따로 쳐야함
전혀 붙어있지 않다? -> 따로의 갯수로 쳐야함

결국 나를 기준으로
감싸냐, 감싸져지냐, 왼쪽에 걸치냐, 오른쪽에 걸치냐로 나눌 수 있음
감싸냐, 감싸져지냐 -> 어차피 전체를 조건식은 하나만 해도 됨 

생각해보니 정렬을 하면됨..

정렬을 기준으로 반복문을 도는데 첫째 인덱스의 끝값이 다음의 첫값을 비교해 인덱스를 밀지 미사일을 늘릴지 정하면 끝인데 뭐한거지
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int i = 0;
    vector<int> visited(targets.size(),0);
    
    sort(targets.begin(),targets.end());
    // for(int i = 0;i<targets.size();i++){
    //     cout<<"i = "<<targets[i][0]<<targets[i][1]<<" ";
    // }
    
    while(i < targets.size()){
        int now_end = targets[i++][1];
        answer++;
        while(i < targets.size() && targets[i][0] < now_end){
            if(targets[i][1] < now_end)
                now_end = targets[i][1];
            i++;
        }
    }
    
    return answer;
}
