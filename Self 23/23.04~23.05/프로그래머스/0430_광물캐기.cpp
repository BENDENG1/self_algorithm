/*
곡괭이중 아무거나 하나를 선택해 광물을 캠 사용할 수 없을때까지 사용
주어진 순서대로만 캘 수 있음 , 최대 5회를 캐는 과정
1  1  1
5  1  1
25 5  1 
최소 피로도를 보여줘야함

복기 : 한번 광물을 캘때에 대해서 입력값을 거꾸로 하는 실수를 범해버렸다.
아무리 논리적인 구조에 대해서 파헤쳐봐도 맞지 않나..? 했는데 곡괭이가 돌일때 다이아몬드를 채취할때 1이 나오는 것을 확인하고 수정했음
*/
#include <iostream>
#include <string>
#include <vector>
int ft_min = 1250; // 최대 광물 50,피로도 25 max = 1250
int cnt = 0;

using namespace std;

void calc_min(vector<string> minerals,vector<int> picks, int sum,int idx);
int calc_tired(vector<string> minerals,vector<int> picks, int idx,int tools);
int calc_time(string m, int tools);

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    //최대 정해진 횟수를 일단 구해야함
    for(int i = 0; i < picks.size();i++){
        cnt+=picks[i];
    }
    cnt *= 5;
    //광물을 캐는 횟수를 정하는데 만약 미네랄의 벡터 크기보다 크다면 전체를 돌 수 있는거임
    //예시 2번을 보고 11개의 광물을 10번까지만 캘 수 있는것으로 확인 가능
    if(cnt>minerals.size()){
        cnt = minerals.size();
    }
    calc_min(minerals,picks,0,0);
    
    answer = ft_min;
    return answer;
}

// 최솟값 및 dp로 계산 구하는 함수
void calc_min(vector<string> minerals,vector<int> picks, int sum,int idx){
    if(idx >= cnt){
        if(ft_min > sum){
            ft_min = sum;
            cout<<"ft_min = "<<ft_min<<"\n";
        }
        return;
    }
    for(int i = 0 ; i < 3;i++){
        if(picks[i] > 0){
            int num = calc_tired(minerals,picks,idx,i);
            picks[i] -= 1;
            calc_min(minerals,picks,sum+num, idx + 5);
            picks[i] += 1;
        }
    }
}

//5회를 돌면서 피로도를 계산해주는 함수
int calc_tired(vector<string> minerals,vector<int> picks, int idx,int tools){
    int sum = 0;
    
    if(idx >= cnt){
        return 0;
    }
    else if(idx + 5 < cnt){
        for(int i = idx; i < idx + 5; i++){
            sum += calc_time(minerals[i],tools);
        }
    }else if(idx + 5 >= cnt){
        for(int i =idx;i < cnt; i++){
            sum += calc_time(minerals[i],tools);
        }    
    }
    return sum;
}


//각각 어떤 광물에 대해서 어떻게 값을 구해야 하는 함수
int calc_time(string m, int tools){
    if(m =="diamond"){
        if(tools == 0){
            return 1;
        }else if(tools == 1){
            return 5;
        }else{
            return 25;
        }
    }else if(m == "iron"){
        if(tools == 2){
            return 5;
        }else{
            return 1;
        }
    }else{
        return 1;
    }
}