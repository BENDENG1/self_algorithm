/*
후보키

유일성과 최소성을 만족해야함 

그냥 문자열 을 더해서 모든것이 다르다면 다른것이 아닐까?

후보키가되는 칼럼의 vector<int> v를 통해 idx를 push_back을 해서 그것을 아예 포함안 vector가 있다면 최소성 x로 추출
유일성은 문자열들을 다 더해버려 근데 같은게 있다면 false

그렇게 dfs 완탐으로 진행하면?

*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> visited;
vector<int> v;
vector<vector<int>> candidate;
int answer = 0;

bool checkCandidate(const vector<vector<string>> &relation){
    //최소성과 유일성을 만족시키는지 확인
    vector<string> unique;
    bool isMinimal = false;
    
    //유일성
    for(int i = 0 ; i < relation.size();i++){
        string tmp = "";
        for(int j = 0; j < v.size();j++){
            tmp += relation[i][v[j]];
        }
        if(find(unique.begin(),unique.end(), tmp) != unique.end())
            return false;
        unique.push_back(tmp);
    }
    
    //최소성
    for(int i = 0; i < candidate.size();i++){
        isMinimal = false;
        for(int j = 0; j < candidate[i].size();j++){
            if(find(v.begin(),v.end(), candidate[i][j]) == v.end()){
                isMinimal = true;
                break;
            }
        }
        if(!isMinimal)
            return false;
    }
    
    return true;
}

void dfs(int idx, int cnt, int total, const vector<vector<string>> &relation){
    if(cnt == total){
        if(checkCandidate(relation)){
            candidate.push_back(v);
            answer++;
        }
        return;
    }
    for(int i = idx; i < relation[0].size();i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            dfs(i,cnt+1,total,relation);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(vector<vector<string>> relation) {
    visited.resize(relation[0].size(),false);
    
    for(int i = 1 ; i <= relation.size();i++)
        dfs(0,0,i,relation);
    
    return answer;
}