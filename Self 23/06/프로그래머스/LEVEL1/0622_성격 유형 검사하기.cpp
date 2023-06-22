/*
성격 유형 검사하기
유형이 4개가 있음  총 16개가 나옴 AN,CF,MJ,RT등 4세트 로 나오게 되는거
음 갱신을 해야하는건데 이럴때 map을 쓰면 항상 제격이라고 느낀단 말이지
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char,int> scoreMap{
        {'R',0},{'C',0},{'J',0},{'A',0},
        {'T',0},{'F',0},{'M',0},{'N',0}
    };
    
    for(int i = 0; i < survey.size();i++){
        int score = choices[i] - 4;
        if(score < 0){            
            scoreMap[survey[i][0]] += abs(score);
        }else if (score > 0){
            scoreMap[survey[i][1]] += score;
        }
    }
    
    // >=의 이유는 사전순이므로
    answer += scoreMap['R'] >= scoreMap['T'] ? 'R' : 'T';
    answer += scoreMap['C'] >= scoreMap['F'] ? 'C' : 'F';
    answer += scoreMap['J'] >= scoreMap['M'] ? 'J' : 'M';
    answer += scoreMap['A'] >= scoreMap['N'] ? 'A' : 'N';
    
    return answer;
}