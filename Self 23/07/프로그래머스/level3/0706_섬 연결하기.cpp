/*
섬 연결하기는

간선의 갯수 = 노드의 갯수 - 1 로 짜게 되며 비용을 기준으로 오름차순으로 정렬을 하고 가장 최솟값에 대해서 처리를 해야지

크루스칼 알고리즘
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool costCompare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int getParent(int idx, vector<int> nodes){
    if(nodes[idx] == idx)
        return idx;
    return nodes[idx] = getParent(nodes[idx],nodes);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> nodes(n,0);
    
    sort(costs.begin(),costs.end(),costCompare);
    for(int i = 0; i < n;i++){
        nodes[i] = i;
    }
    for(int i = 0; i < costs.size();i++){
        int connect = getParent(costs[i][0],nodes); //연결 시작점
        int connected = getParent(costs[i][1],nodes); // 연결 받는점 -> 물론 양뱡향인데 표현을 위해
        int cost = costs[i][2];
        
        if(connect != connected){
            answer+= cost;
            nodes[connected] = connect;
        }
    }
    return answer;
}