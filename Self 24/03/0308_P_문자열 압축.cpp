/*
문자열 압축

1은 생략함 압축률이 낮음 

몇개 단위로 자를지에 대해서 진행하기

우선적으로 한개 두개 세개 4개 짜르는게 의미가 있나? 근데 1000이하의 문자열 길이면 그럴지도

한가지 숫자로 자를 수 있다는 것이 가장 큰 포인트
제일 앞부터 정해진 길이 만큼 잘라야하는 것 5번의 예시로 결국 앞에서 부터 안되면 잘리는거임
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 1000;
    
    if (s.length() == 1)
        return 1;
    
    for(int i = 1 ; i <= s.length() / 2;i++){
        string str = s.substr(0,i);
        string tmp = "";
        int cnt = 1;
        
        for(int j = i; j <= s.length();j += i){
            if(s.substr(j,i) == str){
                cnt++;
            }else{
                if (cnt > 1){
                    tmp += to_string(cnt) + str;
                    str = s.substr(j,i);
                }else{
                    tmp += str;
                    str = s.substr(j,i);
                }
                cnt = 1;
            }
        }
        tmp += str;
        if(answer > tmp.length()) answer = tmp.length();
    }
    return answer;
}
