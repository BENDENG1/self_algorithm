/*
이모티콘 할인 행사

최대로 가입자 늘리기 -> 판매액 늘리기

n명의 m개를 할인 판매 10~40% 중 하나로 설정

이모티콘마다 할인율 설정 10,20,30,40으로 설정

일단은 모든것을 40%할인을 한다는 전제하에 조금씩 가격을 올릴때 이모티콘 플러스 가입자가 줄지 않는 것을 계산한다.

1번 이모티콘부터 40 -> 30 -> 20 -> 10 이런식으로 dfs를 하면 어떨까?
*/
#include <string>
#include <vector>

using namespace std;

vector<int> v;
int discount[4] = {10,20,30,40};
int subs = 0;
int prices = 0;

void dfs(const vector<vector<int>> &users, const vector<int> &emoticons){
    if(v.size() != emoticons.size()){
        for(int i =0; i < 4; i++){
            v.push_back(discount[i]);
            dfs(users,emoticons);
            v.pop_back();
        }
    }else{
        int subsSum = 0;
        int pricesSum = 0;
        
        for(int i = 0; i < users.size();i++){
            int tmp = 0;
            
            for(int j = 0 ; j < emoticons.size(); j++){
                if(users[i][0] <= v[j]){
                    tmp += emoticons[j] * (100 - v[j]) / 100;
                }
            }
            if(tmp >= users[i][1])
                subsSum++;
            else
                pricesSum += tmp;
        }
        if(subsSum > subs){
            subs = subsSum;
            prices = pricesSum;
        }else if(subsSum == subs && pricesSum > prices){
            prices = pricesSum;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(users,emoticons);    
    answer.push_back(subs);
    answer.push_back(prices);

    return answer;
}