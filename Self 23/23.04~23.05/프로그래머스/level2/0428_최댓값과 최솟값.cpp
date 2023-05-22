#include <string>
#include <vector>

using namespace std;
int ft_atoi(char c);

string solution(string s) {
    string answer = "";
    string str ="";
    int min,max;
    int num = 0;
    
    if(s[0] == '-'){
        int tmp = 0;
        while(s[++tmp] != ' '&&s[tmp]){
            num *= 10;
            num += ft_atoi(s[tmp]);
        }
        num *= -1;
    }else{
        int tmp = 0;
        while(s[tmp] != ' '&&s[tmp]){
            num *= 10;
            num += ft_atoi(s[tmp]);
            tmp++;
        }
    }
    min = num;
    max = num;
    
    for(int i = 0; i < s.length();i++){
        num = 0;
        if(s[i] == '-'){
            while(s[++i] != ' '&&s[i]){
                num *= 10;
                num += ft_atoi(s[i]);
            }
            num *= -1;
        }else if('0' <= s[i] && s[i] <= '9'){
            while(s[i] != ' ' && s[i]){
                num *= 10;
                num += ft_atoi(s[i]);
                i++;
            }
        }
        if(max < num)
            max = num;
        if(min > num)
            min = num;
    }
    
    answer += to_string(min);
    answer +=" ";
    answer += to_string(max);
    
    
    return answer;
}


int ft_atoi(char c){
    return (c - '0');
}