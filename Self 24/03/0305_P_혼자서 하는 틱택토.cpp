/*
혼자서 하는 틱택토

선공o 후공 x 9칸이 모두 차서 더이상 표시x 무승부

규칙을 지켰으면 1 아니라면 0 return

1. 두개의 갯수 o가 +1 혹은 같은지 체크
2. 같다면 둘다 틱택토가 완성 됐는지

3*3이라서 행으로 가로 확인 열로 세로 확인 대각선 확인하면 끝인데
끝?
*/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool check(const vector<string>& board, char c){
    
    //대각선
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    
    //가로 세로
    for(int i = 0 ; i < 3;i++){
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;
    }
    return false;
}

int solution(vector<string> board) {
    int first = 0;
    int last = 0;
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[i].length();j++){
            if(board[i][j] == 'O')
                first++;
            else if(board[i][j] == 'X')
                last++;
        }
    }
    if(first < last || abs(first - last) > 1)
        return 0;
    if(check(board, 'O') && first - 1 != last)
        return 0;
    if(check(board, 'X') && first != last)
        return 0;
    // 이거 있었는데 생각해보니 위에 조건문을 통해 걸러줌
    // if(check(board, 'O') && check(board, 'X'))
    //     return 0;

    
    return 1;
}