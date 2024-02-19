
/*
연속 펄스 부분 수열의 합

1,-1,1,-1 또는 -1,1,-1,1임
여기서 이제 어떻게하면 최댓값인지 확인하기

내 생각에는 일단은 sequence에 대해서 +로시작 -로 시작에 대한 vector를 저장함

그러고 최댓값 찾으면 끝..?

dp로 갱신하면서 하면 끝 아닌가?

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<long long> plus;
    vector<long long> minus;
    
    
    for(int i = 0 ; i < sequence.size(); i++){
        if(i % 2 == 0){
            plus.push_back(sequence[i]);
            minus.push_back(sequence[i] * -1);
        }else{
            plus.push_back(sequence[i] * -1);
            minus.push_back(sequence[i]);
        }
    }
    
    for(int i = 1 ; i < sequence.size();i++){
        if(plus[i-1] >= 0){
            plus[i] += plus[i - 1];
        }
        if(minus[i-1] >= 0){
            minus[i] += minus[i - 1];
        }
        answer = max({answer, minus[i],plus[i]});
    }
    
    answer = max({answer, minus[0],plus[0]});
    return answer;
}