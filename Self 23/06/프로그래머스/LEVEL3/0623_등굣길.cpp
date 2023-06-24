/*
잠기지 않은 지역을 통해 학교를 가려함

시작은 왼쪽위 도착지점은 오른쪽 아래이니 

지점에 대해서 왼쪽과 위에 대한 갯수를 더해서 dp를 하면 되지 않을까 싶다.
왜냐하면 오른쪽아니면 아래만 이동이 가능하기 때문
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[100][100]={0,};
    dp[0][0] = 1;
    for(int i = 0; i < puddles.size();i++){
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1; // -1은 웅덩이
    }
    
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            //위랑 왼쪽에 대해 범위 안 그리고 웅덩이x일때 추가
            if(i-1 >= 0 &&dp[i-1][j] != -1 && dp[i][j] != -1){
                dp[i][j] += dp[i-1][j];
            }
            if(j - 1 >= 0 && dp[i][j-1] != -1 && dp[i][j] != -1){
                dp[i][j] += dp[i][j-1];
            }
            dp[i][j] %= 1000000007;
        }
    }
    return dp[n-1][m-1];
}