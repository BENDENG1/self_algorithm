/*
달리기 경주

결국 플레이어의 위치를 찾아서 한칸 앞으로 스왑을 하면 된다는거

모두 소문자이고 중복값은 필요x 현재 1등인 선수는 불리지 않음

callings에서 불리는 이름을 찾는다 -> players의 이름이 있는 인덱스와 인덱스 -1을 스왑한다.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    //시간초과로 인한 map으로 설정 
    map <string, int> playerMap;
    for(int i = 0; i < players.size();i++){
        playerMap[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size();i++){
        //맵에서 랭크를 뽑아옴(등수)
        int playerRank = playerMap[callings[i]];
        
        //스왑할 것을 미리 맵에 갱신
        playerMap[players[playerRank]] = playerRank - 1;
        playerMap[players[playerRank - 1]] = playerRank; 
        
        //서로 스왑
        swap(players[playerRank], players[playerRank - 1]);
    }
    answer = players;
    return answer;
}