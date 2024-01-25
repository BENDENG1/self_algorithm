/*
멀쩡한 사각형

대각선인 지나갈때 포함되지 않은 사각형을 구하라는 거니

w * h - 각도에 따른 없어지는거

음 생각을 해보면 완전 정사각형이 아니면 
*/

#include <algorithm>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    
    answer = (long long)w * (long long)h - w - h;
    answer += __gcd(w,h);
    return answer;
}