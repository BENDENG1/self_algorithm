/*
부대복귀

유일한 번호로 구분 모두 시간 1임 
최단 시간 부대 복귀 

bfs는 말이 안됨 100000개면 다 진행해야할텐데 그건 아닌듯

근데 그냥 bfs로 모든 곳을 방문에 대해서 입력을 해주면 되지 않을까?
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    queue<pair<int,int>> q;
    vector<int> v[100001];
    vector<int> cost(n+1,-1);
    
    
    for(int i = 0 ; i < roads.size();i++){
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    
    q.push({destination,0});
    cost[destination] = 0;
    
    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for(int i = 0; i < v[num].size();i++){
            if(cost[v[num][i]] == -1 || cost[v[num][i]] > cnt + 1){
                q.push({v[num][i],cnt + 1});
                cost[v[num][i]] = cnt + 1;
            }
        }
    }
    
    for(int i = 0; i < sources.size();i++){
        answer.push_back(cost[sources[i]]);
    }
    
    return answer;
}