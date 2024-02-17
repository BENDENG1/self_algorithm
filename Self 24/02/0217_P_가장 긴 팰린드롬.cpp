/*
가장 긴 팰린드롬

문자열 s s의 부분문자열 가장 긴거 return

앞뒤를 뒤집어도 하는 건데 음 문자열의 최대 길이는 2500이다.

dp로 푸는 것이 좋지 않을까?

그 자리부터 양옆으로(일단 범위 내에 있는것는 체킹 기본) 같을때 +를 하면서 반복 한다. 

근데 여기서 문제가 문자열의 길이가 짝수일 때도 고려를 해야한다.

하지만
짝수개를 고려하려면 완전대칭이거나 모든것이 같아야하고 
홀수개를 고려하려면 하나를 기준으로 대칭 혹은 모든것이 같아야함

모든것이 같은것은 결국 홀수,짝수 대칭을 거르면서 거르게 되는것이네
*/
#include <iostream>
#include <string>

using namespace std;


int solution(string s)
{
    int answer = 1;
    
    for(int i = 0; i < s.length(); i++){
        int left = i;
        int right = i + 1;
        int cnt,idx;
        
        cnt = 0;
        while(1){
            if(left < 0 || right >= s.length())
                break;
            if(s[left--] == s[right++]){
                cnt += 2;
            }else{
                break;
            }
        }
        answer = cnt > answer ? cnt : answer;
        
        cnt = 1;
        idx = 1;
        while(1){
            if(i - idx < 0 || i + idx >= s.length())
                break;
            if(s[i - idx] == s[i + idx]){
                cnt += 2;
                idx++;
            }else{
                break;
            }   
        }
        answer = cnt > answer ? cnt : answer;
    }

    return answer;
}