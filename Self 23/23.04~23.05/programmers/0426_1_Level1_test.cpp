#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    long long num = 0;

    for(int i = 0; i < n;i++){
        if(x>0){
            num  +=x;
            answer.push_back(num);
        }else if (x<0){
            num -= x;
            answer.push_back(-num);
        }else{
            answer.push_back(0);
        }
        // answer.push_back(num);
    }

    return answer;
}