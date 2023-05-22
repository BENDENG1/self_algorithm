/*
일정 피로도를 사용해서 
최소 필요 피로도 소모 피로도
dungeons -> 최소필요 피로도, 소모 피로도
k - > 현재 피로도

던전의 개수 1이상 8이하
*/

#include <string>
#include <vector>

using namespace std;
int visited[8] ={0,};
int answer = 0;
void dfs(int cnt, int energy, vector<vector<int>> dungeons,int *minTired, int *useTired);

int solution(int k, vector<vector<int>> dungeons) {
    int min_tired[8];
    int use_tired[8];
    
    int num  = dungeons.size();
    for(int i = 0 ; i <dungeons.size();i++){
        min_tired[i]  = dungeons[i][0];
        use_tired[i] = dungeons[i][1];
    }
    dfs(0,k,dungeons,min_tired,use_tired);
    
    return answer;
}


void dfs(int cnt, int energy,vector<vector<int>> dungeons,int *minTired, int *useTired){
    for(int i =0; i < dungeons.size();i++){
        if(!visited[i] && minTired[i] <= energy){
            visited[i] = true;
            dfs(cnt+1,energy - useTired[i], dungeons, minTired, useTired);
            visited[i] = false;
        }
    }
    answer = answer > cnt ? answer : cnt;
}