/*
소수 찾기 길이 1~7
주어진 numbers의 모든 조합에 대해서 소수의 갯수를 찾는 문제.
주의 : 011 -> 11임

일단 우선적으로 짝수 x, 모든합의 3의배수x

모든 조합에 대해서 확인을 해봐야하는데..
이거는 algorithm헤더에 next_permutation이 있음

그렇게 벡터에 추가한 벡터에 대해서 중복을 지워주고 소수를 판별하면 됨.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    
    vector<int> v;
    vector<int> permutation; //모든 조합들에 대한 백터
    
    for(int i = 0 ; i< numbers.length();i++){
        v.push_back((numbers[i] - '0'));
    }
    sort(v.begin(),v.end());
    
    do{
        int num = 0;
        for(int i = 0; i < v.size();i++){
            num *= 10;
            num += v[i];
            permutation.push_back(num);
        }
    }while(next_permutation(v.begin(),v.end())); //모든 조합에 대해서 진행
    
    sort(permutation.begin(),permutation.end()); //모든 조합들에 대해 정렬
    permutation.erase(unique(permutation.begin(),permutation.end()),permutation.end()); //중복 제거
    
    for(int i = 0; i < permutation.size();i++){
        int PrimeFlag = 1; //소수플래그
        if(permutation[i] < 2)
            continue; // 0혹은 1은 소수아님
        else if(permutation[i] == 2){
            answer++;
            continue;
        }
        for(int j = 2;j<=sqrt(permutation[i]);j++){
            if(permutation[i] % j == 0 || permutation[i] % 2 == 0){
                PrimeFlag = 0;
                break;
            }
        }
        if(PrimeFlag == 1){ //소수일때 ++
            answer++;
        }
    }
    return answer;
}