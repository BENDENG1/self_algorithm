/*
키패드 누르기
왼쪽은 *에서 시작 오른쪽은 #에서 시작
147은 왼쪽
369는 오른쪽
2580은 최근 가까운쪽
둘다 같으면 hand기준
그냥 map쓰면 끝일듯?

그리고 2580을 눌렀다고 상관이 없는게 결국 높이로 비교를 하면 되는게 결국
가로^2+ 세로^2를 해도 결국 가로가 1이므로 높이 1높은게 무조건 높음.

아씨 이동거리를 가로 세로 1로 쳤구나.. 
*/
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

map <string,pair<int,int>> handMap; //handMap으로 왼쪽 오른쪽 현재 위치 파악

//left -> true right -> false
bool leftCheck(int y, int x,bool isLeft){
    int left = abs(handMap["left"].first - y) + abs(handMap["left"].second - x);
    int right = abs(handMap["right"].first - y) + abs(handMap["right"].second - x);
    if(left < right){
        return true;
    }else if(left > right){
        return false;
    }else{
        if(isLeft)
            return true;
        else
            return false;
    }
}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    //왼손,오른손 잡이 판별
    bool isLeft = 1;
    if(hand == "right")
        isLeft = 0;
    
    //처음 *과 #에 있으므로 위치 설정
    handMap["left"] = {3,0};
    handMap["right"] = {3,2};
    
    for(int i = 0; i < numbers.size();i++){
        int y = (numbers[i] - 1) / 3; // y좌표
        int x = (numbers[i] - 1) % 3; // x좌표
        if(numbers[i] == 0){
            y = 3;
            x = 1;
        }
        if(numbers[i] == 1|| numbers[i] == 4||numbers[i] == 7){
            answer+= "L";
            handMap["left"] = {y,x}; // 높이 위치 파악
        }else if(numbers[i] == 3||numbers[i] == 6||numbers[i] == 9){
            answer+="R";
            handMap["right"] = {y,x};
        }else{
            bool left = leftCheck(y,x,isLeft);
            if(left){
                answer+="L";
                handMap["left"] = {y,x};
            }else{
                answer += "R";
                handMap["right"] = {y,x};
            }
        }
    }
    return answer;
}