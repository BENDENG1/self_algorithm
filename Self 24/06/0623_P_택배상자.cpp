/*
택배 상자

한방향으로만 진행이 가능 

4 3 1 2 5이면
1 2 3 -> 보조
4 -> 첫번째니 실음 1
3, 5 중에 3을 실음 -> 2
1이와야하지만 5,2이니 끝
*/
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> s;
    
    for(int i = 1 ; i <= order.size(); i++){
        s.push(i);
        
        while(!s.empty() && s.top() == order[answer]){
            s.pop();
            answer++;
        }
    }
    
    return answer;
}