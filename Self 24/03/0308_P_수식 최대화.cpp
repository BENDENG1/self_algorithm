
/*
수식 최대화 

+, - ,* 만 사용 가능하고 우선순위를 부여해서 절대값이 가장 큰 값을 가지면 됨

잘못된 연산식의 입력은 주어지지 않음 -> 고려 x
음수의 수식 x -> 첫 고려 x
적어도 1개 이상의 연산자를 포함하고 있음

3가지에 대한 우선순위에 대해서 세가지 부호연산에 대해서 3!의 경우의 수를 모두 구해 곱하면 끝 아님? -> 시간 고려는 할 필요 없을듯

음 그냥 우선순위를 0,1,2로 부여를 해서 진행하는거는 

두개의 벡터 숫자들, 부호들로 모아서 연산이 진행될때 숫자 두개를 삭제하고 부호 하나 삭제 하면서 벡터를 갱신하면 되지 않을까
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long long> numV;
vector<char> expV;
vector<long long> numCopy;
vector<char> expCopy;

bool isExp(char c){
    if(c == '-' || c == '*' || c == '+')
        return true;
    return false;
}
long long calc(char c,long long num1, long long num2);
long long getNumber(char first, char second, char third);

long long solution(string expression) {
    long long answer = 0;
    int idx = 0;
    int originalIdx = 0;
    vector<char> cArr{'-', '+', '*'};
    
    int num = 0;
    while(1){
        if(isExp(expression[idx])){
            numV.push_back(num);
            expV.push_back(expression[idx]);
            num = 0;
        }else if(idx == expression.length()){
            numV.push_back(num);
            break;
        }else{
            num *= 10;
            num += (int)(expression[idx] - '0');
        }
        idx++;
    }
    
    //숫자, 표현에 대해 vector에 push_back을 완료한 상태
    //이제 우선순위를 부여해서 진행을 하면 됨
    //* + - 순서로 테스트 해보자
    // answer = max({getNumber('*','+','-'),
    //               getNumber('*','-','+'),
    //               getNumber('+','-','*'),
    //               getNumber('+','*','-'),
    //               getNumber('-','+','*'),
    //               getNumber('-','*','+')});
    
    //위에꺼보다 아래깨 그나마 조금 더 깔끔하지 않나?
    sort(cArr.begin(),cArr.end());
    do{
        long long result = getNumber(cArr[0],cArr[1],cArr[2]);
        answer = answer > result ? answer : result;
    } while(next_permutation(cArr.begin(), cArr.end()));
    
    return answer;
}

long long calc(char c,long long num1, long long num2){
    
    if(c == '-')
        return num1 - num2;
    else if(c == '*')
        return num1 * num2;
    else
        return num1 + num2;
}

void updateChange(char exp){
    int idx = 0;
    while(1){
        if(expCopy.size() == idx){
            break;
        }
        if(expCopy[idx] == exp){
            long long result = calc(exp,numCopy[idx],numCopy[idx + 1]);
            numCopy.erase(numCopy.begin() + idx, numCopy.begin() + idx + 2);
            numCopy.insert(numCopy.begin() + idx, result);
            expCopy.erase(expCopy.begin() + idx, expCopy.begin() + idx + 1); 
        }else{
            idx++;
        }
    }
}

long long getNumber(char first, char second, char third){
    numCopy = numV;
    expCopy = expV;
    int idx = 0;
    
    updateChange(first);
    updateChange(second);
    updateChange(third);
    
    if(numCopy.front() < 0)
        return -numCopy.front();
    return numCopy.front();
}