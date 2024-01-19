/*
1,10,100 10^c인 정수 (절댓값)

0보다 작은거는 움직이지 x
0층이 가장아래층이며 현재 층

최소 횟수를 찾는 거니 bfs로 풀어볼까?

-> 5보다 크면 +1 을 반복하며
-> 5보다 작으면 -1을 반복한다
-> 5일때는? -> 마이너스를 했을 때 5보다 큰지 작은지 판단
*/
#include <string>
#include <vector>

using namespace std;



int solution(int storey) {
    int answer = 0;
    while(storey != 0){
        int step = storey % 10;
        
        if(step > 5){
            answer += (10 - step);
            storey /= 10;
            storey += 1;
        } else if (step < 5){
            answer += step;
            storey /= 10;
        }else{
            int next = (storey / 10) % 10;
            if(next >= 5){
                storey /= 10;
                storey = storey + 1;
            }else{
                storey /= 10;
            }
            answer += 5;
        }
    }
    return answer;
}
