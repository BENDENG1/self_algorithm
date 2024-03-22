/*
햄버거 만들기

순서에 맞게 

순서는 빵 야채 고기 빵 으로 1 2 3 1 순서가 나와야함

*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int idx = 0;
    
    
    while(ingredient.size() > 3 && idx < ingredient.size() - 3){
        if(ingredient[idx] == 1 && ingredient[idx + 3] == 1 && ingredient[idx + 1] == 2 && ingredient[idx + 2] == 3){
            ingredient.erase(ingredient.begin() + idx,ingredient.begin() + idx + 4);
            answer++;
            if(idx > 3){
                idx -= 3;
            }else idx = 0;
        }else{
            idx++;
        }
    }
    
    
    return answer;
}