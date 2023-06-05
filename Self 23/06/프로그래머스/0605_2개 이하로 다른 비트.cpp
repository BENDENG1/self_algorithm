/*
2개 이하로 다른 비트

x보다 크고 x와 비트가 1~2개 다른 수들중에서 가장 작은수

만약 짝수라면? 그냥 맨 뒤에 + 1을 하고 return 왜냐? 더 커야해서

음 그냥 0이 나올때까지에 대해서 계속 비트를 밀어(*2를한다) 근데 0이 나온다? -> break
그리고 break된 bit 2로 나눠
1010111 일때 bit는 그럼 8이 되는거지
1010111 + 1000을하면? -> 10101111이 되어서 가장 낮은 x보다 큰 수가 나옴.

만약 11111이라면? bit가 32가 되고 11111 + 10000 -> 101111이 되어서 만족하는거임
*/
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    
    for(int i = 0; i < numbers.size();i++){
        if(numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else{
            long long bit = 1;
            while(1){
                if((numbers[i] & bit) == 0)
                    break;
                bit *= 2;
            }
            bit /= 2;
            answer.push_back(numbers[i] + bit);
        }
    }
    return answer;
}