/*
하노이 탑 

1,2,3번 있는데 결국 갯수에 따라서 3번에 큰->작 순으로 쌓이게 하는 최소 방법 찾기

여기서 가장 중요한 포인트는 n개가 있다면 n을 3번에 옮기고 다른 것은 2번에 1~n-1까지 다 쌓여 잇는 것이다.

그것을 계속 재귀적으로 반복하는 것이 문제의 핵심인 것 같다.

1이라면 바로 3번으로 이동 1회
2이라면 n-1인 1이 2번으로 가야 2번이 3으로 이동 3회
3이라면 n-1인 1,2가 2번으로 가야 3이 3으로 이동 7회

즉 2^n -1이 최솟값이고 재귀가 100%!인 문제.
*/
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int num, int from, int by, int to);

vector<vector<int>> solution(int n) {
    hanoi(n,1,2,3);
    return answer;
}

void hanoi(int num, int from, int by, int to){
    if(num == 1){
        answer.push_back({from,to});
    }else{
        hanoi(num-1,from,to,by);
        answer.push_back({from,to});
        hanoi(num-1,by,from,to);
    }
}