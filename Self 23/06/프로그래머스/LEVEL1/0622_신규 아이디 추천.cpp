/*
신규 아이디 추천

소문자,숫자,-,-,. 사용 가능
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    int i = 0;
    
    for(int i = 0; i < new_id.length();i++){
        //1단계 대문자 -> 소문자
        new_id[i] = tolower(new_id[i]);
    }
    for(int i = 0; i < new_id.length();i++){
        //2단계 소문자,숫자,빼기,밑줄,마침표를 제외한 모든 문자 제거
        if(!(('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')){
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    
    for(int i = 0; i < new_id.length();i++){
        //3단계 ..2이상 -> 지움
        if(i < new_id.length() - 1 && new_id[i] == '.' && new_id[i + 1] == '.'){
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    for(int i = 0; i < new_id.length();i++){
        //4단계 처음이나 끝이면제거
        if ((i == 0 || i == new_id.length() - 1) && new_id[i] == '.'){
            new_id.erase(new_id.begin()+i);
            i--;
        }
    }
    
    //5단계 -> 비어있다면 a
    if(new_id.empty())
        new_id = "a";
    
    //6단계 16자 이상 첫 15개를 제외한 다 지움 맨 뒤에 .이 있다면 제거
    if(new_id.length() >= 16){
        new_id = new_id.substr(0,15);
        //맨마지막 .이라면 제거
        if(new_id[14] == '.')
            new_id.erase(new_id.begin() + 14);
    }
    
    //7단계 2자 이하라면 붙히기
    if(new_id.length() <= 2){
        while(new_id.length() < 3){
            new_id += new_id.back();
        }
    }
    
    return new_id;
}