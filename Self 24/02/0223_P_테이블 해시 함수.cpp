/*
테이블 해시 함수

col번째 값을 기준으로 오름차순 정렬 -> 동일 기본키 기준 내림차순
정렬 된 것을 i번째 행의 튜플에 대해 i로 나눈 나머지들의 합으로 정의

2 2 6
1 5 10
4 2 9
3 8 3

1 2 3
2 2 6
3 5 9
4 8 10



*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx = 0;

bool compare(vector<int> &a,vector<int> &b){
    if(a[idx] == b[idx]){
        return a[0] > b[0];
    }
    return a[idx] < b[idx];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int sum = 0;
    idx = col - 1;
    
    sort(data.begin(),data.end(),compare);
    
    for(int i = row_begin; i <= row_end; i++){
        sum = 0;
        for(int j = 0; j < data[0].size(); j++){
            sum += (data[i - 1][j] % i);
        }
        answer ^= sum;
    }
    
    return answer;
}