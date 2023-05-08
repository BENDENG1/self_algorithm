/*
문득 생각을 해봤는데 2의 n제곱에 대해서 합을 생각해보면 되지 않을까?

라고 생각하고 노트를 펴 검산을 해보니 맞다.

*/

#include <iostream>
using namespace std;

void dfs(int n,int idx,int energy);
int solution(int n)
{
    int ans = 0;
    int i = 1;
    int sum = 0;
    
    while (i <= n){
        i *= 2; // 5000 이면 8192까지 가는거임
    }
    if(i > n)
        i /= 2; // 8192는 5000보다 크므로 /2를 함 근데 512같이 딱 떨어질 수도 있음
    
    if(n == 1){
        return 1;
    }
    
    while (sum != n){
        if(sum + i <= n){
            sum += i;
            ans++;
        }
        if(sum == n)
            break;
        i /= 2;
    }

    return ans;
}


