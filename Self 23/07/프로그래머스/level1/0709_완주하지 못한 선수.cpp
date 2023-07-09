/*
완주하지 못한 선수

완주자에서 참여자를 뺀 나머지 결국 완주를 못한 사람은 제한사항을 따른 한명뿐이다.

생각을 해보니 그냥 completion에 대해서 먼저 map을 추가하고 키값이 false라면 그걸 리턴하면 되지 않을까?

근데 세번째 예시와 제한사항에 중첩이 있을 수 있다니 int로 선언하고 ++을 해준다. -> 0이라면 return해준다.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> m; //참여자와 완주여부
    
    for(int i = 0; i < completion.size();i++){
        m[completion[i]] += 1;
    }
    for(int i = 0; i < participant.size();i++){
        if(m[participant[i]] == 0)
            return participant[i];
        else
            m[participant[i]] -= 1;
    }
}