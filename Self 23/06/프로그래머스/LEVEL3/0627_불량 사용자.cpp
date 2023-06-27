#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int visited[10] ={0,};
set<int> s;

//주어진 조건에 따른 *를 제외한 길이와 문자가 일치하지 않을때 return false
bool matchPattern(string &pattern, string &s){
    if(pattern.length() != s.length()){
        return false;
    }
    for(int i = 0; i < pattern.length();i++){
        if(pattern[i] != s[i] && pattern[i] != '*'){
            return false;
        }
    }
    return true;
}

void dfs(vector<string> user_id, vector<string> banned_id,int idx){
    if(idx == banned_id.size()){
        //이부분에서 중복에 대한 처리를 해줘야해서 set으로 처리
        int num = 0;
        for(int i = 0; i < user_id.size();i++){
            if(visited[i] == 1){
                num *= 10;
                num += i;
            }
        }
        s.insert(num);
        return;
    }
    
    for(int i = 0; i < user_id.size();i++){
        if(!matchPattern(banned_id[idx],user_id[i])|| visited[i] == 1){ //일치x 바로 넘어가버림
            continue;
        }
        //패턴이 일치할경우 진행
        visited[i] = 1;
        dfs(user_id,banned_id,idx + 1);
        visited[i] = 0;
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id,0);
    int answer = s.size();
    return answer;
}