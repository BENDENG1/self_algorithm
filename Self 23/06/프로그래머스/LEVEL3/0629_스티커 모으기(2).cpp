/*
스티커 모으기

몇장의 스티커를 뜯어냉어 적힌 숫자의 합이 최대

길이 1~100000 // 투포인터 알고리즘? 음 dp?

어떠한 인덱스에 대해서 선택을 했을때에 대해서는 다른것은 선택이 안됨
지금 여기 인덱스를 클릭할때 양옆을 클릭하지 못함

음.. 결국 첫번째를 골랐을때 (두번째, 마지막 클릭못함)
두번째를 골랐을때 (첫,세번째 클릭 못함)
에 대한 dp를 두개 만들어 최댓값을 구하면 될듯 싶은데? -> 그냥 하나로 지우고 다시하면 되지

결국 아무리 숫자가 커도 고를수 있는 두개 앞에서 하나는 골라야한다.
즉, 첫번째 두번째 스티커를 고르고 난 후 진행을 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int size = sticker.size();
    if(size == 1) return sticker[0];
    vector<int> dp;
    
    
    //첫번째꺼를 골랐을때
    dp.push_back(sticker[0]);
    dp.push_back(sticker[0]);

    //처음선택 -> 마지막선택x
    for(int i = 2;i < size - 1;i++){
        //전꺼에서 골랐던가 아님 전전꺼에서 고른것중 최댓값 갱신
        dp.push_back(max(dp[i-2] + sticker[i], dp[i-1]));
    }
    answer = *max_element(dp.begin(),dp.end());
    cout<<answer;
    dp.clear();
    
    //두번째껄 골랐을때
    dp.push_back(0);
    dp.push_back(sticker[1]);
    
    for(int i =2; i < size;i++){
        dp.push_back(max(dp[i-2] + sticker[i],dp[i-1]));
    }
    answer = answer > *max_element(dp.begin(),dp.end()) ? answer : *max_element(dp.begin(),dp.end());

    return answer;
}