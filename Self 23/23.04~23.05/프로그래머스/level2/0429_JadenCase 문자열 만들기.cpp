#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if('a' <= s[0] && s[0] <= 'z'){
        answer += (s[0] - 32);
    }else{
        answer += s[0];
    }
    
    for(int i = 1; i < s.length();i++){
        if(s[i-1] == ' '&&'a' <= s[i] && s[i] <= 'z'){
            answer += (s[i] - 32);
        }else if(s[i-1]!= ' ' && 'A' <= s[i] && s[i] <= 'Z'){
            answer += (s[i] + 32);
        }else{
            answer += s[i];
        }
    }
    
    return answer;
}