#include <string>
#include <vector>

using namespace std;

char push_alphabet(char c, int n);
int is_alpha(char c);

//97~122 소문자
//65~90 대문자
string solution(string s, int n) {
    string answer = "";

    for(int i = 0; i < s.length();i++){
        if(is_alpha(s[i])){
            answer.push_back(push_alphabet(s[i],n));
        }else{
            answer.push_back(s[i]);
        }
    }


    return answer;
}

int is_alpha(char c){
    if('a' <= c && c <= 'z'){
        return 1;
    }else if('A' <= c && c<='Z')
        return 1;
    return 0;
}


char push_alphabet(char c, int n){
    char r_c;

    //wxyz  w 6 c가 되는거니 'a' + 2 가 되는거니 'z' - 'w' = 3 + 1 
    if('a' <= c && c <= 'z'){
        if(c + n > 'z'){
            r_c = 'a' + ('z' - c);
        }else{
            r_c = c + n;
        }
    }else if('A'<=c &&c <='Z'){
        if(c + n > 'Z'){
            r_c = 'A' + ('Z' - c);
        }else{
            r_c = c + n;
        }
    }
    return r_c;
}