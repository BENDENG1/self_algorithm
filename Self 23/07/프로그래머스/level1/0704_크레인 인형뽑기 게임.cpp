/*
크레인 인형 뽑기 게임

0은 빈칸 1~100으로 모양의 인형
같은 인형이 들어오면 사라짐 -> 스택
*/
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < moves.size();i++){
        int idx = moves[i] - 1;
        for(int j = 0; j < board.size();j++){
            if(board[j][idx] != 0){
                if(!s.empty() && s.top() == board[j][idx]){
                    answer+=2;
                    s.pop();
                }
                else
                    s.push(board[j][idx]);
                board[j][idx] = 0;
                break;
            }
        }
    }
    return answer;
}