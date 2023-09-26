/*
딱 봐도 나 dp야 하는 문제 같다.

대각선 오른쪽 왼쪽만 이동 가능 -> 전 idx ->  현재 idx,idx+1을 진행.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = 1; i < triangle.size();i++){
        //케이스를 맨 왼쪽, 맨 오른쪽, 가운데 기준으로 생각하면 되지 않을까?
        //이거를 그냥 맘 편하게 양쪽에 0을 넣어버리면 편할듯?
        // 0 7 0 -> 3 8이니깐  또 0 10 15 0 -> 8 1 0 비교 편함!
        triangle[i-1].insert(triangle[i-1].begin(),0);
        triangle[i-1].push_back(0);
        for(int j  = 0; j < triangle[i].size();j++){
            if(triangle[i-1][j] > triangle[i-1][j+1])
                triangle[i][j] += triangle[i-1][j];
            else
                triangle[i][j] += triangle[i-1][j+1];
        }
    }
    
    // 맨 마지막 바닥 원소에 대해서 크기 측정
    answer = *max_element(triangle[triangle.size()-1].begin(),triangle[triangle.size() -1].end());
    
    
    return answer;
}