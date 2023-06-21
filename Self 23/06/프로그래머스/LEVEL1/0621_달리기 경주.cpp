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