/*
석유 시추

세로 n 가로 m 

세로에 같이 있으면 그것은 무조건 뽑히면 dfs로 돌리면 되는듯 visited를 이용해서 진행하면 될듯

처음에 시간 초과가 난 이유는 무엇일가? -> 그것은 x,y좌표에 대해서 dfs를 돌려서 생긴 문제가 아닐가 싶다.
가장 큰 에러는 visited를 한 시추를 구하고 나서 초기화하는게 문제였다.

그래서 그것을 보완하고자 visited의 초기화는 없이 계속 true false를 진행하게 되며
시추를한 것에 대해서 ans배열을 통해 미리 더해주는 형식으로 진행을 하였다.

*/

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool visited[501][501] = {false,};
int answer = 0;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int ans[501] = {0,};
int oilExist[501] = {false};

int dfs(int x, int y, const vector<vector<int>> &land);

int solution(vector<vector<int>> land) {
    
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < land[0].size(); j++){
            if(visited[i][j] || land[i][j] == 0)
                continue;
            int sum = dfs(j, i, land);
            for(int k = 0; k < land[0].size(); k++){
                if(oilExist[k]){
                    oilExist[k] = false;
                    ans[k] += sum;
                }
            }
        }
    }
    
    for(int i = 0 ; i < land[0].size() ; i++){
        answer = answer > ans[i] ? answer : ans[i];
    }
    
    return answer;
}


/*
일단 dfs로 방문하였는지 오일이 있는지 확인을 하고 그것에 대해서 dfs를 돌림
*/
int dfs(int x,int y, const vector<vector<int>> &land){
    if(land[y][x] == 0 || visited[y][x])
        return 0;
    int sum = 1;
    oilExist[x] = true;
    visited[y][x]  = true;
    
    for(int i = 0 ; i < 4; i ++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size())
            continue;
        if(land[ny][nx] == 0 || visited[ny][nx])
            continue;
        sum += dfs(nx, ny, land);
    }
    return sum;
}