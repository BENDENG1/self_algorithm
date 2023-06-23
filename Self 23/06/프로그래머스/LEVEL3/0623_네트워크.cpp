/*
네트워크

i -> j 연결 ->computer[i][j],computer[j][i]=1 로 연결x -> 0
computer[i][i]는 항상 1

dfs로 풀면 될듯?
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[200]={0,};
int answer = 0;

void dfs(int i,vector<vector<int>> computers);

int solution(int n, vector<vector<int>> computers) {
    answer = computers.size();
    for(int i = 0; i < computers.size();i++){
        if(visited[i] ==0)
            dfs(i,computers);
    }
    return answer;
}

void dfs(int i, vector<vector<int>> computers){
    visited[i] = 1;
    for(int idx = 0; idx < computers.size();idx++){
        if(visited[idx] == 0 && computers[i][idx] == 1){
            if(i!= idx)
                answer --;
            dfs(idx,computers);
        }
    }
}