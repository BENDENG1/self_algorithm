/*
15591번 mootube
1~5000개의 동영상을 올려놓음
연관동영상 리스트를 만드려고함 유사도 체크
유사도가 K이상인 동영상을 추천되도록 BUT 너무 많이 추천 되는것 방지

입력 : N Q -> N-1개의 줄에는 두 동영상 쌍의 유사도, q개는 농부 존의 q개의 질문
1 2 3 -> 1번과 2번의 유사도 3  //이해 : 1,2는3/ 2,3은 2/ 2,4는 4이므로 1과 3은 min(3,2) = 2/ 
2 3 2 -> 2번과 3번의 유사도 2
2 4 4 -> 2번과 4번의 유사도 -> 4
k = 1 2동영상 -> 3 -> 1 3의 유사도 MIN(1,2) = 3
k = 4 1동영상 -> 0 -> 1 4의 유사도 MIN()
k = 3 1동영상 -> 2 -> 
위의 세줄을 기반으로 1 3의 유사도는 2가 되고 1과 4의 유사도는 3이 된다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<pair<int,long long>>> v;
vector<int> visited;
int n,q;

void bfs(long long min_usado,int node);

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    int node1,node2; // 유사도 임시 체크
    long long usado; // 유사도의 범위가 1,000,000,000이므로 int범위를 초과하여 따로 설정
    int node;
    long long min_usado;

    cin>>n>>q;
    v.assign(n+1,vector<pair<int,long long>>(0,{0,0}));

    for (int i = 0; i < n - 1; i++)
    {
        cin >> node1 >> node2 >> usado;
        v[node1].push_back(make_pair(node2, usado));
        v[node2].push_back(make_pair(node1, usado));
    }

    for(int i = 0; i <q;i++){
        cin>>min_usado>>node;
        bfs(min_usado,node);
    }
}

void bfs(long long min_usado,int node){
    int cnt = 0;
    vector<int> visited(n + 1,0);
    visited[node] = true;

    queue<pair<long long, int>> q;
    q.push({min_usado,node});

    while(!q.empty()){
        int cur_usado = q.front().first;
        int cur_node = q.front().second;
        q.pop();

        for(int i = 0; i <v[cur_node].size();i++){
            int next_usado = v[cur_node][i].second;
            int next_node = v[cur_node][i].first;

            if(visited[next_node] == 0 && next_usado >= min_usado){
                visited[next_node] = 1;
                cnt++;
                q.push({next_usado,next_node});
            }
        }
    }
    cout<<cnt<<"\n";
    return;
} 