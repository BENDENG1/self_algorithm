/*
영어 끝말잇기

1~n 까지 끝말잇기를 함

한글자는 인정x

*/
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    
    for(int i = 1 ; i < words.size();i++){
        if(words[i][0] != words[i-1].back()){
            answer.push_back(i % n + 1);
            answer.push_back((i / n) + 1);
            break;
        }
        if(s.find(words[i]) == s.end()){
            s.insert(words[i]);
        }else{
            answer.push_back(i % n + 1);
            answer.push_back((i / n) + 1);
            break;
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}