/*
여행경로

ICN에서 출발
대문자 세글자 / 주어진 항공권 모두 사용 가능한 경로가 두개 -> 알파벳 순서대로 -> 사전순 정렬?!

*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool visited[10000]={false,};
vector<string> answer;
map<string,int> m;
int cnt = 0;


bool compare(vector<string>& a, vector<string>& b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }else{
        return a[0] < b[0];
    }
}

void dfs(vector<vector<string>> tickets, int idx,int cnt);

vector<string> solution(vector<vector<string>> tickets) {
    
    int idx = 0;
    sort(tickets.begin(),tickets.end(),compare);
    
    for(int i = 0; i < tickets.size();i++){
        //결국 시작점이 겹치는 것에 대해서는 사전순으로 정렬된 맨 앞의 인덱스가 저장이 됨
        if(m.find(tickets[i][0]) == m.end()){
            m[tickets[i][0]] = i;
            if(tickets[i][0] == "ICN")
                idx = i;
        }
    }
    
    answer.push_back("ICN");
    dfs(tickets,m[tickets[idx][0]],0);
    
    return answer;
}

void dfs(vector<vector<string>> tickets, int idx,int cnt){
    if(cnt == tickets.size())
        return;
    
    visited[idx] = true;
    answer.push_back(tickets[idx][1]);
    
    if(idx + 1< tickets.size() && tickets[idx + 1][0] == tickets[idx][0]){
        m[tickets[idx][0]] = idx + 1;
    }
    
    if(!visited[m[tickets[idx][1]]])
        dfs(tickets,m[tickets[idx][1]],cnt+1);
}


/*
고친 풀이 -> 뭐가 문제였나? map으로 하게 되는것도 괜찮지만 결국 중복에 대해서 처리를 못함 aaa -> bbb 이런거 두개면 안됨
그리고 aaa -> ddd -> ccc -> aaa -> bbb 만 가능할때 aaa -> bbb 를 먼저 가버리면 갈수 없는것에 대해서 처리를 못함
-> 깊이는 가능했지만 문제에서 못가는 경우는 없다고 해서 괜히 획기적인 풀이하려하다가 map으로 삽을 푼듯.. 정석으로
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001];
bool finish = false;

void dfs(string start,vector<vector<string>> tickets,int cnt);

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    dfs("ICN",tickets,0);
    
    return answer;
}

void dfs(string start,vector<vector<string>> tickets,int cnt){
    if(cnt == tickets.size()){
        finish = true;
    }
    
    answer.push_back(start);
    for(int i = 0; i < tickets.size();i++){
        if(!visited[i] && tickets[i][0] == start){
            visited[i] = true;
            dfs(tickets[i][1],tickets,cnt+1);
            
            if(!finish){
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

