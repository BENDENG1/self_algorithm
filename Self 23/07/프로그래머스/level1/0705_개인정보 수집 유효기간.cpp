#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> m; // 약관, 기관 저장 맵
    
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,7));
    int todayDay = stoi(today.substr(8,10));
    
    for(int i = 0; i < terms.size();i++){
        m[terms[i][0]] = stoi(terms[i].substr(2));
    }
    
    for(int i = 0; i < privacies.size();i++){
        int pastYear = stoi(privacies[i].substr(0,4));
        int pastMonth = stoi(privacies[i].substr(5,7));
        int pastDay = stoi(privacies[i].substr(8,10));
        char term = privacies[i][11];
        int difference = 0;
        
        difference = (todayYear - pastYear) * 12; //월별로 계산을 위해
        
        difference += todayMonth - pastMonth;
        difference *= 28;
        difference += todayDay - pastDay;
        
        if(m[term] * 28 <= difference){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}