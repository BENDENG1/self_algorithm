/*
비슷한 순열 

수들을 중복없이 나열한 것을 순열 

비슷한 순열 -> 각 위치의 수들의 차이가 1이하인 경우

dfs / 백트래킹 -> 백트래킹?

노놉 규칙이 있음

내 숫자보다 -1이 방문x라면 걔랑 나랑 스왑 걔는 무조건 높은숫자

그리고 1이 먼저 등장하면 그냥 1임 -> 낮은순이니 다른 숫자는 낮은 숫자가 가능한ㄷ ㅔ얘는 불가


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[50001];
int numArr[50001];
bool visited[500001] = {false,};


void backTracking(int idx,int sign);

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin>> n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin>> arr[i];
        numArr[i + 1] = i + 1;
    }

    for(int i = 0 ; i < n; i++){
        int idx = arr[i];
        
        if(numArr[idx] == idx + 1){
            visited[idx] = true;
            v.push_back(idx + 1);
        }
        else if(idx != 1 && numArr[idx] == idx && numArr[idx - 1] == idx - 1 && visited[idx - 1] == false){
            visited[idx - 1] = true;
            v.push_back(idx - 1);
            int temp = numArr[idx];
            numArr[idx] = numArr[idx - 1];
            numArr[idx - 1] = temp;
        }else{
            visited[idx] = true;
            v.push_back(idx);
        }
    }

    for(auto a : v){
        cout<<a<<" ";
    }
}
