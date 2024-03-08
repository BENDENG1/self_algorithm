/*
숫자 블록

적힌 번호가 n 일 때 n*2번째 위치에 설치 n*3,4,...

결국 소수판별을 하면서(배제하기) + 나눠지면 가장 먼저 나눠지는거

아니 계속 삽푸다가 천만까지 숫자인거 아... 이거 너무 하네
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i = begin;i <= end; i++){
        if(i == 1){
            answer.push_back(0);
            continue;
        }
        long long num = 1;
        for(long long j = 2; j * j <= i; j++){
            if (i % j == 0){
                num = j;
                if (i / j <= 10000000){
                    num = i / j;
                    break;
                }
            }
        }
        answer.push_back(num);
    }
    return answer;
}