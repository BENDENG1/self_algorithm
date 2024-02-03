
/*
t초 -> 1초마다 x 만큼 회복 / 전체성공 -> y 회복

공격 -> 취소 / 공격 -> 회복 x 공격당하면 연속 성공시간 0

bandage -> 시전시간 초당회복량, 추가 회복량 정수배열
attack[i] -> 공격시간 피해량 정수배열

그냥 하라는대로 빼고 회복하고 시전시간되면 추가회복하고 최대 hp안넘기고 끝인듯
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int firstHealth = health;
    int turn = 0;
    int idx = 0;
    
    for(int i = 0 ; i <= attacks[attacks.size() - 1][0]; i++){
        if(i == attacks[idx][0]){
            turn = 0;
            health -= attacks[idx][1];
            if(health <= 0)
                return -1;
            idx++;
        }else{
            health += bandage[1];
            if(turn == bandage[0]){
                turn = 0;
                health += bandage[2];
            }
            if(health >= firstHealth)
                health = firstHealth;
        }
        turn++;
    }
    return health;
}