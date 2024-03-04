/*
두 원 사이의 정수 쌍

그냥 dp로 측정하고 버리는 거는?

한사분면만 측정을 하면 다른 곳 *4를 하면 된다 (+하나의 축)

근데 모든점을 측정하라는 건 아닐텐데 

아니면 반지름 제곱 - x축의 제곱에 대해 제곱근을 두개다 구해서 그 사이 값을 측정한다면?

작은원은 높힘 큰원은 내림을 해서 이상,이하의 값을 구하면 되는듯 싶은데

걍 반지름 제곱 빼기 x좌표 제곱 빼서 그 사이 값 다 더해서 *4
*/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i = 1; i <= r2; i++){
        int y1, y2;    
        y2 = floor(sqrt(pow(r2,2) - pow(i,2)));
        if(i <= r1){
            y1 = ceil(sqrt(pow(r1,2) - pow(i, 2)));
            answer += (y2 - y1 + 1);
        }else{
            answer += (y2 + 1);
        }
    }
    
    return answer * 4;
}