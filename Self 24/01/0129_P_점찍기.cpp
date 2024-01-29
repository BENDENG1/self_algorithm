/*
점 찍기

d를 넘는 곳에는 찍지 않음

음.. 그럼 경계값을 계산해서 그 아래는 갯수를 + 를 하는 것은 어딸까?

나누기를 해서 + 1 갯수를 하면 되려나?

근데 100만개면 음 전체를 계산하는 것은 아니고

그냥 제곱근을 구해서 더하면 끝 아닌가?
*/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0 ; i < d; i += k){
        answer += (long long)sqrt(1ll *d * d - 1ll * i*i) / k;   
    }
    answer += d/k + 1;
    
    return answer;
}