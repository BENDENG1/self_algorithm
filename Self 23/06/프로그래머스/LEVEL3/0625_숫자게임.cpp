/*
xx회사의 2xN명의 사원들 n명씩 두팀나눠 숫자게임

무작위 자연수 / 딱 한번 경기 / 큰쪽이 승리

a가 공개 b가 최대의 승수 만드는법 -> 그냥 결국 그 값의 큰값중에 가장 큰값을 가져옴

a를 sort함 -> b의 가장 비슷한 큰값을 가져옴
1 3 5 7
2 2 6 8

1 2 / 3 6 / 5 8 -> 다른 케이스도 많지만 결국 이것이 최대의 값임은 분명함!
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int idxA = 0;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    for(int i = 0; i < B.size();i++){
        if(A[idxA] < B[i]){
            answer++;
            idxA++;
        }
    }
    return answer;
}