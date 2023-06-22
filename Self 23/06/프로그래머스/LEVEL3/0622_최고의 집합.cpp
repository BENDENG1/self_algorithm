/*
최고의 집합

자연수 n개로 이루어진 중복집합
원소의 개수 n과 모든 원소들의 합 s

곱이 최대려면 최대한 s/n에 근접하는게 가장 최선 아닐까?
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int sum = 0;
    int overCnt = s % n; //결국 8887 이런식이 가장 크므로 888이렇게 overCnt를 측정
    
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i =0;i<n;i++){
        if(i < overCnt){
            answer.push_back(s/n + 1);
        }else{
            answer.push_back(s/n);
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}