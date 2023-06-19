/*
n을 입력받아 x부터 시작을 해 x씩 증가하는 숫자룰 n개 지니는 리스트를 리턴
*/

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for(int i = 0; i < n;i++){
        answer.push_back(x+i*x);
    }
    
    return answer;
}