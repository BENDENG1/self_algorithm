/*
순위

1~n 1대1방식으로 진행 
경기 결과 분실 순위 매길 수 x

정확하게 순위를 매길 수 있는 선수의 수 return

n명의 선수의 승,패의 총합은 무조건 n-1임

일단 누군가에게 졌다면 무조건 그 선수 아래임

각각의 패배한 선수의 파워라고 정의하고 진행하는 것은 어떨까?
는 아닌거 같음 

1 2 /  2 3 라는 소리는 2는 1한테 졌고 3은 2한테 진거면 3은 1한테 지는게 맞는거 아닌가?
이거 그 알고리즘 그 뭐야 플로이드 와샬 
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool visited[101][101] = {false,};
    
    
    for(int i = 0 ; i < results.size(); i ++){
        visited[results[i][0]][results[i][1]] = true;
    }
    
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<= n; j++){
            for(int k = 1; k <= n; k++){
                if(visited[j][i] && visited[i][k]){
                    visited[j][k] = true;
                }
            }
        }
    }
    
    for(int i = 1; i<=n;i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(visited[i][j] || visited[j][i])
                cnt++;
        }
        if(cnt == n-1) answer++;
    }
    return answer;
}