/*
N Queen

n인 정사각형 체스판 

무조건 두는 것은 세로에는 하나를 둔다는 전제하에 하는거니깐
2차원을 1차원으로 생각하고 숫자를 넣으면?

인덱스를 열로 생각하고 이제 값을 행으로 생각해서 일차원 배열에 때려 넣으면 될듯
*/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int arr[13] = {0,};
int answer = 0;

void solve(int idx, int n);

int solution(int n) {
    solve(0, n);    
    return answer;
}

void solve(int idx,int n){
    if(idx == n){
        answer++;
        return;
    }
    for(int i = 0 ; i < n; i++){
        arr[idx] = i; 
        bool isRight = true;
        for(int j = 0; j < idx; j++){
            if(arr[idx] == arr[j] || abs(idx - j) == abs(arr[idx] - arr[j])){
                isRight = false;
                break;
            }
        }
        if(isRight){
            solve(idx+1, n);
        }
    }
}

