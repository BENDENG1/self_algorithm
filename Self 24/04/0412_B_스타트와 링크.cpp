/*
스타트와 링크

i, j로 했을 때 i가 j보다 

무조건 0 인덱스는 스타트로 집어넣고 진행을 한다면?
*/
#include <iostream>
#include <algorithm>

int n;
int answer = 2001;
bool visited[20] = {false,};
int arr[20][20] = {0,};
int linkSum = 0;
int startSum = 0;

using namespace std;

void solve(int pos, int cnt){
    if(pos == n && cnt == (n / 2 + n % 2)){
        linkSum = 0;
        startSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i] && visited[j])
                    startSum += arr[i][j];
                else if(!visited[i] && !visited[j])
                    linkSum += arr[i][j];
            }
        }
        if(abs(startSum - linkSum) < answer)
            answer = abs(startSum - linkSum);
        return;
    }

    for(int i = pos; i < n; i++){
        visited[i] = true;
        solve(i + 1, cnt + 1);
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin>> arr[i][j];
        }
    }
    solve(0,0);

    cout << answer;
}