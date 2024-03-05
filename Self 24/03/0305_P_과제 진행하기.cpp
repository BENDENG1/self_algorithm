/*
과제 진행하기

시작,멈춰둔 과제가 있다면 새로운 과제 진행
멈춰둔 과제 여러개일 경우 가장 최근에 멈춰둔 과제부터 시작 함

일단 남은것들은 스택에 넣으면서 남는시간만큼 계속 차감을 해주는데 마지막 원소까지 벡터를 훑으면 그냥

스택은 pop하면서 answer에 push_back해주면 됨
*/
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;


struct assign{
    string name;
    int start;
    int playTime;
};

bool compare(const assign &a,const assign &b){
    return a.start < b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<assign> v;
    stack<assign> s;
    
    for(int i = 0 ; i < plans.size();i++){
        int start = 0;
        int playTime = 0;
        
        start = stoi(plans[i][1].substr(0,2)) * 60 + stoi(plans[i][1].substr(3,2));
        playTime = stoi(plans[i][2]);
        v.push_back({plans[i][0],start,playTime});
    }
    
    sort(v.begin(),v.end(),compare);
    int idx = 0;
    while(1){
        if(idx == v.size() - 1){
            answer.push_back(v[idx].name);
            break;
        }
        if(v[idx].playTime > v[idx+1].start - v[idx].start){
            v[idx].playTime -= (v[idx + 1].start - v[idx].start);
            s.push(v[idx]);
        }else{
            answer.push_back(v[idx].name);
            int leftTime = v[idx + 1].start - v[idx].start - v[idx].playTime;
            while(leftTime > 0 && !s.empty()){
                if(s.top().playTime > leftTime){
                    s.top().playTime -= leftTime;
                    break;
                }else{
                    answer.push_back(s.top().name);
                    leftTime -= s.top().playTime;
                    s.pop();
                }
            }
        }
        idx++;
    }
    
    while(!s.empty()){
        answer.push_back(s.top().name);
        s.pop();
    }
    
    return answer;
}