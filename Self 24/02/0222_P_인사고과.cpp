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

자신보다 큰 점수에 대해서만 비교를 해서 제거를 하면 됨 

왜냐 5점 5점이거나 5점 3점이면 무조건 하나는 크거나 같을 수 밖에 없어서 조건을 충족함
하지만 역으로 3, 5점이면 1,2 2,3 같은 경우에 받지를 못함
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[0] + a[1] > b[0] + b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int score = scores[0][0] + scores[0][1];
    
    for(int i = 0; i < scores.size(); i++){
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
            return -1;
    }
    
    sort(scores.begin() + 1,scores.end(), compare);
    
    for(int i = 1; i < scores.size();i++){
        answer++;
        for(int j = 1; j < i;j++){
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]){
                answer--;
                break;
            }
        }
        if(scores[i][0] + scores[i][1] <= score)
            break;
        
    }
    return answer;
}