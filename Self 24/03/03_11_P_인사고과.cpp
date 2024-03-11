/*
인사 고과

인센티브 -> 하나라도 제일 낮으면 안됨 두 점수가 모두 낮은 경우 한번 -> 인센x 
합이 높은 순으로 석차 -> 인센

a,b 점수가

음 1 4 / 3 3 으로 끝나면 제일 낮은게 아니니 인센을 받긴함

결국 두개다 제일 낮지만 않으면 인센은 일단 받음 -> 즉, 합이 제일 낮지만 않으면 줌

가 아니라 낮으면 안받는다는건가?

1. 완호가 받을 수 있는지 체크
2. 합을 기준으로 정렬을 하고 그들이 받을 자격이 있는지 확인 

여기서 두 점수가 모두 낮으면 못받는거면 사실 자신보다 높은거는 하나는 무조건 있다는거 아님?

근데 여기서 '어떤 사원이 다른 임의의 사우너보다 두 점수가 모두 낮은 경우' 라는 것은 모든 것을 탐색을 해야한다는 말인가?
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = scores.size() + 1;
    int score = scores[0][0] + scores[0][1];
    
    for(int i = 0; i < scores.size(); i++){
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
            return -1;
    }
    
    sort(scores.begin() + 1,scores.end());
    
    for(int i = 1; i < scores.size(); i++){
        if(score >= scores[i][0] + scores[i][1]) continue;
        for(int j = i + 1; j < scores.size(); j ++){
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
            {
                answer--;
                break;
            }
        }
    }
    
    
    for(int i = 0 ; i < scores.size(); i++){
        if(score >= scores[i][0] + scores[i][1])
            answer--;
    }

    return answer;
}