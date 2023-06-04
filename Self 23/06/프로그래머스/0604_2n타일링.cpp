/*
2 * n타일링
길이가 2인 타일을 가로로 혹은 세로로 채울때의 모든 경우를 구하는 것

dp로 푸는것이 최선이라고 생각

1-> 1
2 -> 2
3 -> 3
4 -> 5
5 -> 
n번째 칸은? -> n-1번째 에서 세로 + n - 2번째 칸 가로가로/세로세로 가 아닐까 생각

하지만! n-2칸의 세로세로는 n-1칸에 포함이 됨.

즉, v[i] = v[i-1] + v[i-2]라고 추측
는 아니었음 그렇게 간단할리가ㅋㅋ

응? 맞네..? 나머지를 안해서 그렇네
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    
    for(int i =2;i<n;i++){
        v.push_back((v[i-1] + v[i-2]) % 1000000007);
    }
    return v[n-1];
}