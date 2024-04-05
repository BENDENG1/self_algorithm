/*
연산자 끼워 넣기

백 트레킹으로 구하면 되지 않나?

더하기, 빼기, 곱하기, 나누기 순서대로 저장을 한다.
*/
#include <iostream>
#include <vector>

using namespace std;

int n;
int minNum = 1000000001;
int maxNum = -1000000001;
int symbol[4] = {0,};

void solve(const vector<int> &v,int num, int cnt){
    if(cnt == n - 1){
        if(num < minNum)
            minNum = num;
        if(num > maxNum)
            maxNum = num;
        return;
    }
    for(int i = 0 ; i < 4; i++){
        if(symbol[i] != 0){
            symbol[i]--;

            if(i == 0) 
                solve(v, num + v[cnt + 1], cnt + 1);
            else if (i == 1)
                solve(v, num - v[cnt + 1], cnt + 1);
            else if (i == 2)
                solve(v, num * v[cnt + 1], cnt + 1);
            else
                solve(v, num / v[cnt + 1], cnt + 1);
            
            symbol[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tmp;
    vector<int> v;    

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 0 ; i < 4; i++){
        cin >> tmp;
        symbol[i] = tmp;
    }

    solve(v, v[0] ,0);
    cout << maxNum << "\n" << minNum;
    return 0;
}