/*
가장 먼 노드

1번노드에서 가장 멀리 떨어진 노드의 갯수 -> BFS?

양방향 노드는 20000개 간선 50000개 제한
*/
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<pair<int,int>> q;
    map<int,int> m;
    int maxDistance = 0; 
    vector<vector<int>> arr(n+1,vector<int>(n+1,0));
    int visited[20001] = {0,};
    
    
    for(int i = 0; i < edge.size();i++){
        arr[edge[i][0]][edge[i][1]] = 1;
        arr[edge[i][1]][edge[i][0]] = 1;
    }
    
    visited[1] = 1;
    for(int i = 1 ; i < n + 1;i++){
        if(arr[1][i] == 1){
            q.push({i,1});
            visited[i] = 1;
        }
    }
    while(!q.empty()){
        int idx = q.front().first;
        int cnt = q.front().second;
        m[cnt] += 1;
        q.pop();
        for(int i = 1; i < n+1;i++){
            if(arr[idx][i] == 1 && visited[i] == 0){
                q.push({i,cnt + 1});
                visited[i] = 1;
            }
        }
        maxDistance = cnt;
    }
    
    return m[maxDistance];
}