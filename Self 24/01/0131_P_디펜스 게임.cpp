/*
디펜스 게임

매라운드 enemy[i] / 무적권 소모x k번 있음 / 최대한 많은 라운드 진행

dp로 썼을 때 안 썼을 때를 나누는거는?

음 썼을 때 0 이고 안 썼을 때는 그냥 숫자인데 그때의 n이 닿을 때까지 최솟값을 구하면 되지 않을까?

걍 이럴때 쓰는게 우선순위 큐지 ㅇㅇ

*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int num = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0 ; i < enemy.size();i++){
        pq.push(enemy[i]);
        if(pq.size() > k){
            num += pq.top();
            pq.pop();
        }
        if(num > n)
            return i;
    }
    return enemy.size();
    
    return answer;
}