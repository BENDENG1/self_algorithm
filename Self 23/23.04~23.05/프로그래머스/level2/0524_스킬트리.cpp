/*
음.. 그냥 반복문 돌면서 확인하면 끝 아닌가?

아 아니다 맵을 사용하면 되겠다.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int lastSkill = skill.length() - 1;
    map<char,int> m;
    
    for(int i = 0; i < skill.length();i++)
        m[skill[i]] = i;
    
    for(int i = 0 ; i < skill_trees.size();i++){
        int idx = 0;
        for(int j = 0; j < skill_trees[i].length();j++){
            if(skill_trees[i][j] == skill[idx])
                idx++;
            else{
                //맵에 존재하고 index가 더 크다 -> 뒤에 스킬이다.
                if(m.find(skill_trees[i][j]) != m.end() && m[skill_trees[i][j]] > idx)
                    break;
            }
            //끝에 도달했거나 idx == lastSkill이라는 것은 이제 스킬을 다 사용.
            if(idx == lastSkill || j == skill_trees[i].length() - 1){
                answer++;
                break;
            }
        }
    }
    
    
    return answer;
}